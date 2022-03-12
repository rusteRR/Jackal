#include <QApplication>
#include <QDebug>
#include <iostream>
#include "MainGame.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto mainGame = new jackalui::MainGame;
    mainGame->startGame();
    return QApplication::exec();
}
