#ifndef CLIENT_H_
#define CLIENT_H_

#include <QTime>
#include "MainMenuWidget.h"
#include "FieldWidget.h"
#include "contoller.h"

namespace jackalui {
    class Client : public QWidget {
    Q_OBJECT
    public:
        Client();

        void show();

    public slots:

        void startGame();

        void exitGame();

        void backToMenu();

    private:
        MainMenuWidget* mainMenuWidget;
        FieldWidget* fieldWidget;
        Controller* controller;
    };
}

#endif // CLIENT_H_
