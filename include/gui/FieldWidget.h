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
        explicit FieldWidget(QWidget *parent = nullptr) : QWidget(parent), main_game(jackal::game_type::DEFAULT) {
            auto game_field = main_game.get_field();
            auto menuButton = new QPushButton("Menu", this);
            auto ship = new ShipWidget(this);
            jackal::Ship ship_logic{1, 1};
            connect(ship, &ShipWidget::onPressed, ship, &ShipWidget::MoveShip);
            auto pirate = new PirateWidget(this);
            connect(menuButton, &QPushButton::pressed, this, &FieldWidget::menuButtonPressed);
            menuButton->setMaximumSize(300, 500);
            auto grid = new QGridLayout(this);
            grid->setContentsMargins(410, 10, 410, 10);
            for (int i = 0; i < 13; ++i) {
                for (int j = 0; j < 13; ++j) {
                    auto event = new EventWidget(j, i, main_game.get_field().get_element(j,i), this);
                    grid->addWidget(event, i, j);
                    
                    connect(event, &EventWidget::onPressed, pirate, [event, pirate] { event->addPirate(pirate); });
                }
            }
            ship->raise();
        }

    signals:

        void menuButtonPressed();

    private:
        jackal::Game main_game;
    };
}

#endif //JACKALUI_FIELDWIDGET_H
