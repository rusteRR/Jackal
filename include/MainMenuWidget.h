#ifndef JACKALUI_MAINMENUWIDGET_H
#define JACKALUI_MAINMENUWIDGET_H
#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include "FieldWidget.h"
namespace jackalui {
    class MainMenuWidget : public QWidget {
        Q_OBJECT
    public:
        MainMenuWidget(){
            layout = new QVBoxLayout(this);
            layout->setSpacing(10);
            auto jackal_label = new QLabel(this);
            QPixmap label_pixmap("../pics/jackallabel.png");
            jackal_label->setPixmap(label_pixmap.scaled(2000, 1000, Qt::KeepAspectRatio));
            auto start_button = new QPushButton("Start Game!", this);
            auto exit_button = new QPushButton("Exit", this);
            start_button->setMaximumSize(2000, 500);
            exit_button->setMaximumSize(2000, 500);
            connect(start_button, SIGNAL(pressed()), this, SIGNAL(startButtonPressed()));
            connect(exit_button, SIGNAL(pressed()), this, SIGNAL(exitButtonPressed()));
            layout->addWidget(jackal_label);
            layout->addWidget(start_button);
            layout->addWidget(exit_button);
        }
        
    signals:
        void startButtonPressed();
        void exitButtonPressed();
    private:
        QVBoxLayout* layout;
    };
}


#endif //JACKALUI_MAINMENUWIDGET_H
