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
        connect(controller, &Controller::handle_error, this, &FieldWidget::show_error);
        connect(controller, &Controller::update_names, this, &FieldWidget::update_names);
        connect(controller, &Controller::show_moves, this, &FieldWidget::show_moves);
        menuButton->setMaximumSize(300, 500);

        auto GRID = new QHBoxLayout(this);
        auto players = new QVBoxLayout(this);
        auto FIELD = new QWidget(this);
        auto grid = new QGridLayout(FIELD);

        {QImage image1("icon.png");
        QImage image2("icon.png");
        QImage image3("icon.png");
        QImage image4("icon.png");
        QPainter p1(&image1);
        QPainter p2(&image2);
        QPainter p3(&image3);
        QPainter p4(&image4);
        p1.setFont(QFont("Italic", 34));
        p1.drawText(40, 70, "player1");
        p1.drawText(40, 140, "150");
        QPixmap pirate_blue("pirate1.png");
        p1.drawPixmap(200, 0, pirate_blue);

        p2.setFont(QFont("Italic", 34));
        p2.drawText(40, 70, "player2");
        p2.drawText(40, 140, "150");
        QPixmap pirate_green("pirate2.png");
        p2.drawPixmap(190, 0, pirate_green);

        p3.setFont(QFont("Italic", 34));
        p3.drawText(40, 70, "player3");
        p3.drawText(40, 140, "150");
        QPixmap pirate_purple("pirate3.png");
        p3.drawPixmap(190, 0, pirate_purple);

        p4.setFont(QFont("Italic", 34));
        p4.drawText(40, 70, "player4");
        p4.drawText(40, 140, "150");
        QPixmap pirate_red("pirate4.png");
        p4.drawPixmap(190, 0, pirate_red);

        player1 = new QLabel(this);
        player2 = new QLabel(this);
        player3 = new QLabel(this);
        player4 = new QLabel(this);
        player1->setPixmap(QPixmap::fromImage(image1));
        player2->setPixmap(QPixmap::fromImage(image2));
        player3->setPixmap(QPixmap::fromImage(image3));
        player4->setPixmap(QPixmap::fromImage(image4));}

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
        grid->setHorizontalSpacing(1);
        grid->setVerticalSpacing(1);

        GRID->addWidget(FIELD);
        GRID->addSpacing(300);
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

    void FieldWidget::clear_field() {
        for (int i = 0; i < 13; ++i) {
            for (int j = 0; j < 13; ++j) {
                field[i][j]->clear_frame();
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
            players_coins[i] = player_coins;
            if (cur_pos.first != ship_row || cur_pos.second != ship_col) {
                field[cur_pos.first][cur_pos.second]->removeShip();
                field[ship_row][ship_col]->set_ship(player_id, player_coins);
                cur_ships[i] = {ship_row, ship_col};
            } else {
                field[ship_row][ship_col]->set_ship(player_id, player_coins);
            }

            QJsonArray pirates = player["pirates"].toArray();
            for (int j = 0; j < pirates.size(); ++j) {
                auto pirate = pirates.at(j);
                int pirate_id = pirate["pirate_id"].toInt();
                int pirate_row = pirate["coord_y"].toInt();
                int pirate_col = pirate["coord_x"].toInt();
                bool is_dead = pirate["is_dead"].toBool();
                if (!is_dead) {
                    field[pirate_row][pirate_col]->add_pirate(player_id, pirate_id);
                }
            }
        }
        update_icons();
    }

    void FieldWidget::update_names(const QJsonArray &json) {
        for (int i = 0; i < json.size(); ++i) {
            auto player = json.at(i);
            names[i] = player["name"].toString();
        }
        update_icons();
    }

    void FieldWidget::update_field(const QJsonArray &field_data) {
        clear_field();
        for (int i = 0; i < field_data.size(); ++i) {
            auto cell = field_data.at(i);
            int row = cell["coord_y"].toInt();
            int col = cell["coord_x"].toInt();
            int coins = cell["coins"].toInt();
            bool is_open = cell["is_open"].toBool();
            QString filename = cell["filename"].toString();
            field[row][col]->set_pic(filename);
            if (is_open) {
                field[row][col]->flip();
                field[row][col]->set_coins(coins);
            }
        }
    }

    void FieldWidget::update_icons() {
        QImage image1("icon.png");
        QImage image2("icon.png");
        QImage image3("icon.png");
        QImage image4("icon.png");
        QPainter p1(&image1);
        QPainter p2(&image2);
        QPainter p3(&image3);
        QPainter p4(&image4);

        p1.setFont(QFont("Italic", 34));
        p1.drawText(40, 70, names[0]);
        p1.drawText(40, 140, QString::number(players_coins[0]));
        QPixmap pirate_blue("pirate1.png");
        p1.drawPixmap(200, 0, pirate_blue);

        p2.setFont(QFont("Italic", 34));
        p2.drawText(40, 70, names[1]);
        p2.drawText(40, 140, QString::number(players_coins[1]));
        QPixmap pirate_green("pirate2.png");
        p2.drawPixmap(190, 0, pirate_green);

        p3.setFont(QFont("Italic", 34));
        p3.drawText(40, 70, names[2]);
        p3.drawText(40, 140, QString::number(players_coins[2]));
        QPixmap pirate_purple("pirate3.png");
        p3.drawPixmap(190, 0, pirate_purple);

        p4.setFont(QFont("Italic", 34));
        p4.drawText(40, 70, names[3]);
        p4.drawText(40, 140, QString::number(players_coins[3]));
        QPixmap pirate_red("pirate4.png");
        p4.drawPixmap(190, 0, pirate_red);

        player1->setPixmap(QPixmap::fromImage(image1));
        player2->setPixmap(QPixmap::fromImage(image2));
        player3->setPixmap(QPixmap::fromImage(image3));
        player4->setPixmap(QPixmap::fromImage(image4));
    }

    void FieldWidget::show_moves(const QJsonArray &json) {
        for (int i = 0; i < json.size(); ++i) {
            auto cell = json.at(i);
            int row = cell["coord_y"].toInt();
            int col = cell["coord_x"].toInt();
            field[row][col]->make_possible_to_move();
        }
    }

    void FieldWidget::show_error(const QString &error_message) {
        clear_field();
        qDebug() << "error: " << error_message;
        QMessageBox msgBox;
        msgBox.setWindowTitle("Jackal error");
        msgBox.setText(QString("<font size=28>") + "Error message:" + "</font>");
        msgBox.setInformativeText(QString("<font size=5>") + error_messages.at(error_message) + "</font>");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("QLabel{min-width: 365px;}");
        // msgBox.setStyleSheet("QMessageBox { background-image: url(error_background.png) }"); // TODO: make pretty backgr
        msgBox.exec();
    }
}
