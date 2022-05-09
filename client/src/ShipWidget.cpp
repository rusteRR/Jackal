#include "ShipWidget.h"

namespace jackalui {
    ShipWidget::ShipWidget(QWidget *parent) : QWidget(parent) {
        m_label->setScaledContents(true);
        QString picture_to_set = "ship1.png";
        QPixmap pixmap(picture_to_set);
        m_label->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
        auto layout = new QVBoxLayout(this);
        layout->addWidget(m_label);
        layout->setContentsMargins(0, 0, 0, 0);
    }

    void ShipWidget::mousePressEvent(QMouseEvent *ev) {
        emit onPressed();
    }
}
