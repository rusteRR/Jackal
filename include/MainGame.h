#ifndef JACKALUI_MAINGAME_H
#define JACKALUI_MAINGAME_H
#include <QTime>
#include "MainMenuWidget.h"
#include "FieldWidget.h"
namespace jackalui {
    class MainGame : QObject {
        Q_OBJECT
    public:
        MainGame() : mainMenuWidget(new MainMenuWidget()), fieldWidget(new FieldWidget()){
            connect(mainMenuWidget, SIGNAL(startButtonPressed()), this, SLOT(showField()));
            connect(mainMenuWidget, SIGNAL(exitButtonPressed()), this, SLOT(exitGame()));
            connect(fieldWidget, SIGNAL(menuButtonPressed()), this, SLOT(backToMenu()));
        }
    void startGame() {
        mainMenuWidget->showFullScreen();
    }
    public slots:
        void showField(){
            fieldWidget->showFullScreen();
            QTime microPause = QTime::currentTime().addMSecs(100);
            while (QTime::currentTime() < microPause){}
            mainMenuWidget->hide();
        };
        void exitGame(){
            mainMenuWidget->close();
            fieldWidget->close();
        }
        void backToMenu(){
            mainMenuWidget->showFullScreen();
            QTime microPause = QTime::currentTime().addMSecs(100);
            while (QTime::currentTime() < microPause){}
            fieldWidget->hide();
        }
    private:
        MainMenuWidget* mainMenuWidget;
        FieldWidget* fieldWidget;
    };
}

#endif //JACKALUI_MAINGAME_H
