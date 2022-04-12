#ifndef JACKALUI_FIELDWIDGET_H
#define JACKALUI_FIELDWIDGET_H

#include <QLabel>
#include <QDebug>
#include <QGridLayout>
#include <QPushButton>
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
        FieldWidget(Controller* controller_, QWidget *parent = nullptr) : QWidget(parent), controller(controller_) {
            auto menuButton = new QPushButton("Menu", this);
            connect(menuButton, &QPushButton::pressed, this, &FieldWidget::menuButtonPressed);
            menuButton->setMaximumSize(300, 500);
            auto grid = new QGridLayout(this);
            grid->setContentsMargins(410, 10, 410, 10);
            for (int i = 0; i < 13; ++i) {
                for (int j = 0; j < 13; ++j) {
                    auto event = new EventWidget(j, i, this, controller);
                    grid->addWidget(event, i, j);
                }
            }
            grid->setHorizontalSpacing(0);
            grid->setVerticalSpacing(0);
        }

    signals:

        void menuButtonPressed();

    private:
        Controller* controller;
    };
}

#endif //JACKALUI_FIELDWIDGET_H
