#include <QApplication>
#include <iostream>
#include "MainGame.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto mainGame = new jackalui::MainGame;
    mainGame->init();
    return QApplication::exec();
}
