#include <QApplication>
#include "server.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    qRegisterMetaType<jackal::Field>();
    jackal::Server server;
    server.setMaxPendingConnections(4);
    return a.exec();

}