#ifndef JACKALUI_MAINGAME_H
#define JACKALUI_MAINGAME_H

#include <QTime>
#include "MainMenuWidget.h"
#include "FieldWidget.h"

namespace jackalui {
    class MainGame : public QObject {
    Q_OBJECT
    public:
        MainGame() : mainMenuWidget(new MainMenuWidget()),
                                                       fieldWidget(new FieldWidget()) {
            connect(mainMenuWidget, &MainMenuWidget::startButtonPressed, this, &MainGame::showField);
            connect(mainMenuWidget, &MainMenuWidget::exitButtonPressed, this, &MainGame::exitGame);
            connect(fieldWidget, &FieldWidget::menuButtonPressed, this, &MainGame::backToMenu);;
        }

        void startGame() {
            mainMenuWidget->showFullScreen();
        }

    public slots:

        void showField() {
            fieldWidget->showFullScreen();
            mainMenuWidget->hide();
        }

        void exitGame() {
            mainMenuWidget->close();
            fieldWidget->close();
        }

        void backToMenu() {
            mainMenuWidget->showFullScreen();
            fieldWidget->hide();
        }

    private:
        MainMenuWidget *mainMenuWidget;
        FieldWidget *fieldWidget;
    };
}

#endif //JACKALUI_MAINGAME_H
