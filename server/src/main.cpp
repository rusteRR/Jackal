#include <QApplication>
#include "server.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    jackal::MyTcpServer server;

    return a.exec();

}