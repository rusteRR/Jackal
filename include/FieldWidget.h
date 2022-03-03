#ifndef JACKALUI_FIELDWIDGET_H
#define JACKALUI_FIELDWIDGET_H
#include <QLabel>
#include <QDebug>
#include <QGridLayout>
#include "EventWidget.h"
class FieldWidget : public QWidget{
    Q_OBJECT
public:
    FieldWidget(){
        auto grid = new QGridLayout(this);
        for (auto &event : events){
            grid->addWidget(event);
        }
    }
private:
    QList<EventWidget*> events;
};


#endif //JACKALUI_FIELDWIDGET_H
