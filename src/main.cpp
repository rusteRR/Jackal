#include <QApplication>
#include <QDebug>
#include <QTextEdit>
#include <iostream>
#include "FieldWidget.h"
#include "EventWidget.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    jackalui::FieldWidget fieldWidget;
    fieldWidget.show();
    return QApplication::exec();
}
