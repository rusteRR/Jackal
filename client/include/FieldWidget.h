#ifndef JACKALUI_FIELDWIDGET_H
#define JACKALUI_FIELDWIDGET_H

#include <QLabel>
#include <QDebug>
#include <QGridLayout>
#include <QPushButton>
#include <QJsonObject>
#include <QJsonArray>
#include <QImage>
#include <QPainter>
#include <QSpacerItem>
#include <QMessageBox>
#include <QString>
#include <QJsonDocument>
#include <map>
#include "EventWidget.h"
#include "ShipWidget.h"
#include "PirateWidget.h"
#include "controller.h"

namespace jackalui {
    class FieldWidget : public QWidget {
    Q_OBJECT
    public:
        explicit FieldWidget(Controller *controller_, QWidget *parent = nullptr);

        void update_names(const QJsonArray &json);

        void update_icons();

    signals:

        void menuButtonPressed();

    private slots:

        void set_pics(const QJsonDocument &json);

        void cellOpen(int row, int col);

        void shipMove(int row_from, int col_from, int row_to, int col_to, int id, int money);

        void update_players(const QJsonArray &players_data);

        void update_field(const QJsonArray &field_data);

        void clear_pirates();

        void show_error(const QString &error_message);

    private:
        QLabel* player1 = new QLabel(this);
        QLabel* player2 = new QLabel(this);
        QLabel* player3 = new QLabel(this);
        QLabel* player4 = new QLabel(this);
        Controller *controller;
        QVector<QVector<EventWidget *>> field;
        const std::map<QString, QString> error_messages = {{"take_coin", "There is no coin"},
                                                     {"ship_move", "You can't move ship like that"},
                                                     {"pirate_move", "You can't move pirate like that"},
                                                     {"not cell clicked", "not cell clicked"},
                                                     {"wrong turn", "pirate can only move on cell or ship"}};
        std::map<int, QString> names = { {0, "pirate1"}, {1, "pirate2"}, {2, "pirate3"}, {3, "pirate4"}};
        std::map<int, std::pair<int,int>> cur_ships = {{0, {0, 6}}, {1, {6, 12}}, {2, {12, 6}}, {3,{6, 0}}};
        std::map<int,int> players_coins = {{0, 0}, {1, 0}, {2, 0}, {3, 0} };
    };
}

#endif //JACKALUI_FIELDWIDGET_H
