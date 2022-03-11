#include <QApplication>
#include <QDebug>
#include <iostream>
#include "FieldWidget.h"
#include "EventWidget.h"
#include "MainMenuWidget.h"
#include "MainGame.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    jackalui::MainGame mainGame;
    mainGame.startGame();
    return QApplication::exec();
}
