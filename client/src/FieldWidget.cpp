#include "FieldWidget.h"

namespace jackalui {
    FieldWidget::FieldWidget(Controller *controller_, QWidget *parent) : QWidget(parent), controller(controller_),
                                                                         field(13) {
        //this->setStyleSheet( "background-color: rgb(244,214,96);");
        auto menuButton = new QPushButton("Menu", this);
        connect(controller, &Controller::field_response, this, &FieldWidget::set_pics);
        connect(menuButton, &QPushButton::pressed, this, &FieldWidget::menuButtonPressed);
        connect(menuButton, &QPushButton::pressed, controller_, &Controller::back_to_menu_slot);
        connect(controller, &Controller::open_cell, this, &FieldWidget::cellOpen);
        connect(controller, &Controller::move_ship, this, &FieldWidget::shipMove);
        connect(controller, &Controller::handle_players, this, &FieldWidget::update_players);
        connect(controller, &Controller::handle_field, this, &FieldWidget::update_field);
        menuButton->setMaximumSize(300, 500);

        auto GRID = new QHBoxLayout(this);
        auto players = new QVBoxLayout(this);
        auto FIELD = new QWidget(this);
        auto grid = new QGridLayout(FIELD);

        QImage image1("icon.png");
        QImage image2("icon.png");
        QImage image3("icon.png");
        QImage image4("icon.png");
        QPainter p1(&image1);
        QPainter p2(&image2);
        QPainter p3(&image3);
        QPainter p4(&image4);
        p1.setPen(QPen(Qt::black));
        p1.setFont(QFont("Italic", 34));
        p1.drawText(40, 70, "player1");
        p1.drawText(40, 140, "150");

        QPixmap pirate_blue("pirate_blue.png");
        p1.drawPixmap(200, 0, pirate_blue);
        p2.setPen(QPen(Qt::black));
        p2.setFont(QFont("Italic", 34));
        p2.drawText(40, 70, "player2");
        p2.drawText(40, 140, "150");

        QPixmap pirate_green("pirate_green.png");
        p2.drawPixmap(190, 0, pirate_green);
        p3.setPen(QPen(Qt::black));
        p3.setFont(QFont("Italic", 34));
        p3.drawText(40, 70, "player3");
        p3.drawText(40, 140, "150");

        QPixmap pirate_purple("pirate_purple.png");
        p3.drawPixmap(190, 0, pirate_purple);
        p4.setPen(QPen(Qt::black));
        p4.setFont(QFont("Italic", 34));
        p4.drawText(40, 70, "player4");
        p4.drawText(40, 140, "150");

        QPixmap pirate_red("pirate_red.png");
        p4.drawPixmap(190, 0, pirate_red);

        auto player1 = new QLabel(this);
        auto player2 = new QLabel(this);
        auto player3 = new QLabel(this);
        auto player4 = new QLabel(this);
        player1->setPixmap(QPixmap::fromImage(image1));
        player2->setPixmap(QPixmap::fromImage(image2));
        player3->setPixmap(QPixmap::fromImage(image3));
        player4->setPixmap(QPixmap::fromImage(image4));

        auto spacer = new QSpacerItem(100, 150);
        players->addSpacerItem(spacer);

        players->addWidget(player1);
        players->addWidget(player2);
        players->addWidget(player3);
        players->addWidget(player4);

        auto spacer1 = new QSpacerItem(100, 150);
        players->addSpacerItem(spacer1);

        GRID->addLayout(players);

        for (int i = 0; i < 13; ++i) {
            for (int j = 0; j < 13; ++j) {
                auto event = new EventWidget(j, i, this, controller);
                field[i].push_back(event);
                grid->addWidget(event, i, j);
            }
        }
        grid->setHorizontalSpacing(0);
        grid->setVerticalSpacing(0);

        GRID->addWidget(FIELD);
    }

    void FieldWidget::set_pics(const QJsonDocument &json) {
        qDebug() << json;
        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 13; j++) {
                QString indexes = QString::fromStdString(std::to_string(i) + " " + std::to_string(j));
                field[i][j]->set_pic(json.object().value(indexes).toString());
            }
        }
    }

    void FieldWidget::cellOpen(int row, int col) {
        field[row][col]->flip();
    }

    void FieldWidget::shipMove(int row_from, int col_from, int row_to, int col_to, int id, int money) {
        qDebug() << "Ship" << id << "moved from" << row_from << col_from << "to" << row_to << col_to;
        if (row_to == row_from && col_to == col_from) return;
        field[row_from][col_from]->removeShip();
        field[row_to][col_to]->set_ship(id, money);
    }

    void FieldWidget::clear_pirates() {
        for (int i = 0; i < 13; ++i) {
            for (int j = 0; j < 13; ++j) {
                field[i][j]->remove_pirates();
            }
        }
    }

    void FieldWidget::update_players(const QJsonArray &players_data) {
        clear_pirates();
        for (int i = 0; i < players_data.size(); ++i) {
            auto player = players_data.at(i);
            int ship_row = player["ship_coord_y"].toInt();
            int ship_col = player["ship_coord_x"].toInt();
            int player_id = player["player_id"].toInt();
            int player_coins = player["total_coins"].toInt();
            auto cur_pos = cur_ships[i];
            if (cur_pos.first != ship_row || cur_pos.second != ship_col) {
                field[cur_pos.first][cur_pos.second]->removeShip();
                field[ship_row][ship_col]->set_ship(player_id, player_coins);
                cur_ships[i] = {ship_row, ship_col};
            }

            QJsonArray pirates = player["pirates"].toArray();
            for (int j = 0; j < pirates.size(); ++j) {
                auto pirate = pirates.at(j);
                int pirate_row = pirate["coord_y"].toInt();
                int pirate_col = pirate["coord_x"].toInt();
                bool is_dead = pirate["is_dead"].toBool();
                if (!is_dead) {
                    field[pirate_row][pirate_col]->add_pirate(player_id);
                }
            }
        }
    }

    void FieldWidget::update_field(const QJsonArray &field_data) {
        for (int i = 0; i < field_data.size(); ++i) {
            auto cell = field_data.at(i);
            int row = cell["coord_y"].toInt();
            int col = cell["coord_x"].toInt();
            int coins = cell["coins"].toInt();
            bool is_open = cell["is_open"].toBool();
            QString filename = cell["filename"].toString();
            // TODO: and money
            field[row][col]->set_pic(filename);
            if (is_open) {
                field[row][col]->flip();
                field[row][col]->set_coins(coins);
            }
        }
    }
}
