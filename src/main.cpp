#include <QApplication>
#include <QDebug>
#include <iostream>
#include "FieldWidget.h"
#include "EventWidget.h"
#include "MainMenuWidget.h"
#include "MainGame.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto mainGame = new jackalui::MainGame;
    mainGame->startGame();
    //auto kek = new jackalui::FieldWidget();
    //kek->show();
    return QApplication::exec();
}
