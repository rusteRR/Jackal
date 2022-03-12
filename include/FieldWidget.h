#ifndef JACKALUI_FIELDWIDGET_H
#define JACKALUI_FIELDWIDGET_H

#include <QLabel>
#include <QDebug>
#include <QGridLayout>
#include <QPushButton>  
#include "EventWidget.h"

namespace jackalui {
    class FieldWidget : public QWidget {
    Q_OBJECT
    public:
        explicit FieldWidget(QWidget* parent = nullptr) : QWidget(parent) {
            auto menuButton = new QPushButton("Menu", this);
            connect(menuButton, SIGNAL(pressed()), this, SIGNAL(menuButtonPressed()));
            menuButton->setMaximumSize(300, 500);
            menuButton->show();
            auto grid = new QGridLayout(this);
            grid->setContentsMargins(410, 10, 410, 10);
            for (int i = 0; i < 13; ++i) {
                for (int j = 0; j < 13; ++j) {
                    grid->addWidget(new EventWidget(), i, j);
                }
            }
        }
    signals:
        void menuButtonPressed();
    private:
        //QList<EventWidget*> events;
    };
}

#endif //JACKALUI_FIELDWIDGET_H
