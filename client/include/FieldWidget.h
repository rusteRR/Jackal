#ifndef JACKALUI_FIELDWIDGET_H
#define JACKALUI_FIELDWIDGET_H

#include <QLabel>
#include <QDebug>
#include <QGridLayout>
#include <QPushButton>
#include <QJsonObject>
#include <QString>
#include <QJsonDocument>
#include "EventWidget.h"
#include "ShipWidget.h"
#include "ship.h"
#include "PirateWidget.h"
#include "game.h"
#include "contoller.h"

namespace jackalui {
    class FieldWidget : public QWidget {
    Q_OBJECT    
    public:
        explicit FieldWidget(Controller* controller_, QWidget *parent = nullptr);

    signals:
        void menuButtonPressed();

    private slots:
        void set_pics(const QJsonDocument& json);

        void cellIsOpen(int row, int col);

    private:
        Controller* controller;
        QVector<QVector<EventWidget*>> field;
    };
}

#endif //JACKALUI_FIELDWIDGET_H
