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
                                                       fieldWidget(nullptr) {
            connect(mainMenuWidget, &MainMenuWidget::startButtonPressed, this, &MainGame::startGame);
            connect(mainMenuWidget, &MainMenuWidget::exitButtonPressed, this, &MainGame::exitGame);
        }

        void init() {
            mainMenuWidget->showFullScreen();
        }

    public slots:

        void startGame() {
            fieldWidget = new FieldWidget();
            connect(fieldWidget, &FieldWidget::menuButtonPressed, this, &MainGame::backToMenu);;
            fieldWidget->showFullScreen();
            mainMenuWidget->hide();
        }

        void exitGame() {
            mainMenuWidget->close();
            fieldWidget->close();
            fieldWidget->deleteLater();
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
