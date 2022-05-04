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
        explicit FieldWidget(Controller* controller_, QWidget *parent = nullptr) : QWidget(parent), controller(controller_),
                                                                                   field(13) {
            auto menuButton = new QPushButton("Menu", this);
            connect(controller, &Controller::field_response, this, &FieldWidget::set_pics);
            connect(menuButton, &QPushButton::pressed, this, &FieldWidget::menuButtonPressed);
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

            /*auto play_grid = new QGridLayout(this);
            play_grid->setContentsMargins(410, 10, 410, 10);
            auto ship = new ShipWidget(this);
            play_grid->addWidget(ship, 6, 0);*/
            controller->wait_filename();
        }

    signals:
        void menuButtonPressed();

    private slots:
        void set_pics(const QJsonDocument& json) {
            qDebug() << json;
            for (int i = 0; i < 13; i++) {
                for (int j = 0; j < 13; j++) {
                    QString indexes = QString::fromStdString(std::to_string(i) + " " + std::to_string(j));
                    field[i][j]->set_pic(json.object().value(indexes).toString());
                }
            }
        }

    private:
        Controller* controller;
        QVector<QVector<EventWidget*>> field;
    };
}

#endif //JACKALUI_FIELDWIDGET_H
