#ifndef JACKALUI_MAINMENUWIDGET_H
#define JACKALUI_MAINMENUWIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <QMainWindow>  
#include <QGridLayout>
#include <QApplication>
#include "ExitLabel.h"
#include "GameStartLabel.h"

namespace jackalui {
    class MainMenuWidget : public QWidget {
        Q_OBJECT
    public:
        explicit MainMenuWidget(QWidget* parent = nullptr) : QWidget(parent){
            auto background = new QLabel(this);
            QPixmap headerPixmap("background.png");
            background->setPixmap(headerPixmap.scaled(2000,1100, Qt::KeepAspectRatio));
            background->move(this->width() / 2 + background->width(), 0);
            auto startLabel = new GameStartLabel(this);
            auto exitLabel = new ExitLabel(this);
            startLabel->move(background->pos().x() + 270, 500);
            exitLabel->move(background->pos().x() + 270, 750);
            connect(startLabel, &GameStartLabel::onPressed, this, &MainMenuWidget::startButtonPressed);
            connect(exitLabel, &ExitLabel::onPressed, this, &MainMenuWidget::exitButtonPressed);
        }
    signals:
        void startButtonPressed();
        void exitButtonPressed();
    };
}


#endif //JACKALUI_MAINMENUWIDGET_H
