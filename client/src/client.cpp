#include "client.h"

namespace jackalui {
    Client::Client() : mainMenuWidget(new MainMenuWidget()), fieldWidget(nullptr), controller(new Controller(this)){
        connect(mainMenuWidget, &MainMenuWidget::startButtonPressed, controller, &Controller::start_game);
        connect(mainMenuWidget, &MainMenuWidget::startButtonPressed, this, &Client::startGame);
        connect(mainMenuWidget, &MainMenuWidget::exitButtonPressed, controller, &Controller::end_game);
        connect(mainMenuWidget, &MainMenuWidget::exitButtonPressed, this, &Client::exitGame);
    }

    void Client::show() {
        mainMenuWidget->showFullScreen();
    }

    void Client::startGame() {
        fieldWidget = new FieldWidget(controller);
        connect(fieldWidget, &FieldWidget::menuButtonPressed, this, &Client::backToMenu);
        fieldWidget->showFullScreen();
        mainMenuWidget->hide();
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

