#include <QApplication>
#include <iostream>
#include "client.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    jackalui::Client client;
    client.show();
    return QApplication::exec();
}
