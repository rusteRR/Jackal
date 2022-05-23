#include "client.h"

namespace jackalui {
    Client::Client() : mainMenuWidget(new MainMenuWidget()), fieldWidget(nullptr), controller(new Controller(this)),
                        auth(new AuthorizationWidget(mainMenuWidget, controller)) {
        connect(mainMenuWidget, &MainMenuWidget::startButtonPressed, this, &Client::authUser);
        connect(mainMenuWidget, &MainMenuWidget::exitButtonPressed, controller, &Controller::end_game);
        connect(mainMenuWidget, &MainMenuWidget::exitButtonPressed, this, &Client::exitGame);
        connect(controller, &Controller::authCorrect, this, &Client::startGame);
        connect(controller, &Controller::authCorrect, controller, &Controller::start_game);
    }

    void Client::show() {
        mainMenuWidget->showFullScreen();
    }

    void Client::authUser() {
        auth->showFullScreen();
        mainMenuWidget->hide();
    }

    void Client::startGame() {
        fieldWidget = new FieldWidget(controller);
        connect(fieldWidget, &FieldWidget::menuButtonPressed, this, &Client::backToMenu);
        fieldWidget->showFullScreen();
        // mainMenuWidget->hide();
        auth->hide();
    }

    void Client::exitGame() {
        mainMenuWidget->close();
        fieldWidget->close();
        fieldWidget->deleteLater();
    }

    void Client::backToMenu() {
        mainMenuWidget->showFullScreen();
        fieldWidget->hide();
    }
}

