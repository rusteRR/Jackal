#ifndef JACKALUI_PIRATEWIDGET_H
#define JACKALUI_PIRATEWIDGET_H

#include <QLabel>
#include "controller.h"

namespace jackalui {
    class PirateWidget : public QWidget {
    Q_OBJECT
    public:
        explicit PirateWidget(QWidget *parent = nullptr, Controller *controller_ = nullptr) : QWidget(parent),
                                                                                              controller(controller_),
                                                                                              m_label(new QLabel(
                                                                                                      this)) {
            m_label->setScaledContents(true);
            QString picture_to_set = "pirate1.png";
            QPixmap pixmap(picture_to_set);
            m_label->setPixmap(pixmap);
            auto layout = new QVBoxLayout(this);
            layout->addWidget(m_label);
            layout->setContentsMargins(0, 0, 0, 0);
        }

    private:
        QLabel *m_label;
        int m_id;
        Controller *controller;
    };
}
#endif //JACKALUI_PIRATEWIDGET_H
