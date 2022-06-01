#ifndef JACKALUI_PIRATEWIDGET_H
#define JACKALUI_PIRATEWIDGET_H

#include "controller.h"
#include <QLabel>
#include <QPushButton>

namespace jackalui {
    class PirateWidget : public QWidget {
    Q_OBJECT
    public:
        explicit PirateWidget(QWidget *parent = nullptr, Controller *controller_ = nullptr) : QWidget(parent), controller(controller_) {
            // TODO: for some reason doesn't work as expected
            pirate = new QPushButton(this);
        }

        void setPic() {
            QPixmap pirate_pic("pirate.png");
            QIcon ButtonIcon(pirate_pic);
            pirate->setIcon(ButtonIcon);
            pirate->setIconSize(pirate->rect().size());
            pirate->raise();
        }

    private:
        QPushButton *pirate;
        Controller *controller;
    };
}
#endif //JACKALUI_PIRATEWIDGET_H
