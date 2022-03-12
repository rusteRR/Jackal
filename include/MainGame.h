#ifndef JACKALUI_MAINGAME_H
#define JACKALUI_MAINGAME_H

#include <QTime>
#include "MainMenuWidget.h"
#include "FieldWidget.h"

namespace jackalui {
    class MainGame : public QWidget {
    Q_OBJECT
    public:
        explicit MainGame(QWidget *parent = nullptr) : QWidget(parent), mainMenuWidget(new MainMenuWidget(this)),
                                                       fieldWidget(new FieldWidget(this)) {
            connect(mainMenuWidget, &MainMenuWidget::startButtonPressed, this, &MainGame::showField);
            connect(mainMenuWidget, &MainMenuWidget::exitButtonPressed, this, &MainGame::exitGame);
            connect(fieldWidget, &FieldWidget::menuButtonPressed, this, &MainGame::backToMenu);
        }

        void startGame() {
            mainMenuWidget->showFullScreen();
        }

    public slots:

        void showField() {
            fieldWidget->showFullScreen();
            QTime microPause = QTime::currentTime().addMSecs(100);
            while (QTime::currentTime() < microPause) {}
            mainMenuWidget->hide();
        };

        void exitGame() {
            mainMenuWidget->close();
            fieldWidget->close();
        }

        void backToMenu() {
            mainMenuWidget->showFullScreen();
            QTime microPause = QTime::currentTime().addMSecs(100);
            while (QTime::currentTime() < microPause) {}
            fieldWidget->hide();
        }

    private:
        MainMenuWidget *mainMenuWidget;
        FieldWidget *fieldWidget;
    };
}

#endif //JACKALUI_MAINGAME_H
