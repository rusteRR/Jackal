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

namespace jackalui {
    class FieldWidget : public QWidget {
    Q_OBJECT
    public:
        explicit FieldWidget(QWidget *parent = nullptr) : QWidget(parent) {
            auto menuButton = new QPushButton("Menu", this);
            auto pirate = new PirateWidget(this);
            connect(menuButton, &QPushButton::pressed, this, &FieldWidget::menuButtonPressed);
            menuButton->setMaximumSize(300, 500);
            auto grid = new QGridLayout(this);
            grid->setContentsMargins(410, 10, 410, 10);
            for (int i = 0; i < 13; ++i) {
                for (int j = 0; j < 13; ++j) {
                    auto event = new EventWidget(j, i, this);
                    grid->addWidget(event, i, j);
                    connect(event, &EventWidget::onPressed, pirate, [event, pirate] { event->addPirate(pirate); });
                }
            }
            grid->setHorizontalSpacing(0);
            grid->setVerticalSpacing(0);
        }

    signals:

        void menuButtonPressed();
    };
}

#endif //JACKALUI_FIELDWIDGET_H
