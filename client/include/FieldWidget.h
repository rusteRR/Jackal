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

    signals:

        void menuButtonPressed();

    private slots:

        void set_pics(const QJsonDocument &json);

        void cellOpen(int row, int col);

        void shipMove(int row_from, int col_from, int row_to, int col_to, int id, int money);

        void update_players(const QJsonArray &players_data);

        void update_field(const QJsonArray &field_data);

        void clear_pirates();

    private:
        Controller *controller;
        QVector<QVector<EventWidget *>> field;
        std::map<int, std::pair<int,int>> cur_ships = {{0, {0, 6}}, {1, {6, 12}}, {2, {12, 6}}, {3,{6, 0}}};
    };
}

#endif //JACKALUI_FIELDWIDGET_H
