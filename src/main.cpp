#include <QApplication>
#include <QDebug>
#include <QTextEdit>
//#include "FieldWidget.h"
#include "EventWidget.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    EventWidget event;
    event.show();
    return QApplication::exec();
}
