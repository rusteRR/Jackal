#ifndef CLIENT_H_
#define CLIENT_H_

#include <QTime>
#include "MainMenuWidget.h"
#include "FieldWidget.h"
#include "contoller.h"

namespace jackalui {
    class Client : public QObject {
    Q_OBJECT
    public:
        Client() : mainMenuWidget(new MainMenuWidget()), fieldWidget(nullptr), controller(new Controller(this))  {
            connect(mainMenuWidget, &MainMenuWidget::startButtonPressed, controller, &Controller::start_game);
            connect(mainMenuWidget, &MainMenuWidget::exitButtonPressed, controller, &Controller::end_game);
        }

        void show() {
            mainMenuWidget->showFullScreen();
        }

    public slots:

        void startGame() {
            fieldWidget = new FieldWidget();
            connect(fieldWidget, &FieldWidget::menuButtonPressed, this, &Client::backToMenu);;
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
        MainMenuWidget* mainMenuWidget;
        FieldWidget* fieldWidget;
        Controller* controller;
    };
}

#endif // CLIENT_H_
