#include <QApplication>
#include "server.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    jackal::Server server;
    return a.exec();

}