#include "FieldWidget.h"

namespace jackalui {
    FieldWidget::FieldWidget(Controller *controller_, QWidget *parent) : QWidget(parent), controller(controller_),
                                                                         field(13) {
        auto menuButton = new QPushButton("Menu", this);
        connect(controller, &Controller::field_response, this, &FieldWidget::set_pics);
        connect(menuButton, &QPushButton::pressed, this, &FieldWidget::menuButtonPressed);
        connect(controller, &Controller::open_cell, this, &FieldWidget::cellOpen);
        connect(controller, &Controller::move_ship, this, &FieldWidget::shipMove);
        connect(controller, &Controller::handle_players, this, &FieldWidget::update_players);
        connect(controller, &Controller::handle_field, this, &FieldWidget::update_field);
        menuButton->setMaximumSize(300, 500);
        auto grid = new QGridLayout(this);
        grid->setContentsMargins(410, 10, 410, 10);
        for (int i = 0; i < 13; ++i) {
            for (int j = 0; j < 13; ++j) {
                auto event = new EventWidget(j, i, this, controller);
                field[i].push_back(event);
                grid->addWidget(event, i, j);
            }
        }
        grid->setHorizontalSpacing(0);
        grid->setVerticalSpacing(0);

        //controller->wait_filename();
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

    void FieldWidget::update_players(const QJsonArray &players_data) {
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
        }
    }

    void FieldWidget::update_field(const QJsonArray &field_data) {
        for (int i = 0; i < field_data.size(); ++i) {
            auto cell = field_data.at(i);
            int row = cell["coord_y"].toInt();
            int col = cell["coord_x"].toInt();
            bool is_open = cell["is_open"].toBool();
            QString filename = cell["filename"].toString();
            // TODO: and money
            field[row][col]->set_pic(filename);
            if (is_open) {
                field[row][col]->flip();
            }
        }
    }
}
