#ifndef JACKALUI_FIELDWIDGET_H
#define JACKALUI_FIELDWIDGET_H

#include <QLabel>
#include <QDebug>
#include <QGridLayout>
#include "EventWidget.h"

namespace jackalui {
    class FieldWidget : public QWidget {
    Q_OBJECT
    public:
        FieldWidget() {
            auto grid = new QGridLayout(this);
            grid->setContentsMargins(410, 10, 410, 10);
            for (int i = 0; i < 13; ++i) {
                for (int j = 0; j < 13; ++j) {
                    grid->addWidget(new EventWidget(), i, j);
                }
            }
        }

    private:
        //QList<EventWidget*> events;
    };
}

#endif //JACKALUI_FIELDWIDGET_H
