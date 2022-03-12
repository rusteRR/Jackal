#ifndef JACKALUI_MAINMENUWIDGET_H
#define JACKALUI_MAINMENUWIDGET_H
#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include "FieldWidget.h"
#include "ExitLabel.h"
#include "GameStartLabel.h"
namespace jackalui {
    class MainMenuWidget : public QWidget {
        Q_OBJECT
    public:
        explicit MainMenuWidget(QWidget* parent = nullptr) : QWidget(parent){
            auto layout = new QVBoxLayout(this);
            layout->setSpacing(10);
            auto header = new QLabel(this);
            QPixmap headerPixmap("../pics/jackallabel.png");
            header->setPixmap(headerPixmap.scaled(1000, 500, Qt::KeepAspectRatioByExpanding));
            auto startLabel = new GameStartLabel(this);
            auto exitLabel = new ExitLabel(this);
            connect(startLabel, &GameStartLabel::onPressed, this, &MainMenuWidget::startButtonPressed);
            connect(exitLabel, &ExitLabel::onPressed, this, &MainMenuWidget::exitButtonPressed);
            layout->addWidget(header);
            layout->addWidget(startLabel);
            layout->addWidget(exitLabel);
        }
    signals:
        void startButtonPressed();
        void exitButtonPressed();
    };
}


#endif //JACKALUI_MAINMENUWIDGET_H
