#include "ShipWidget.h"

namespace jackalui {
    ShipWidget::ShipWidget(int id, QWidget *parent, Controller *controller_) : m_id(id), QWidget(parent),
                                                                               m_label(new QLabel(this)),
                                                                               controller(controller_) {
        m_label->setScaledContents(true);
        QString picture_to_set = QString::fromStdString(std::string("ship" + std::to_string(id) + ".png"));;
        QPixmap pixmap(picture_to_set);
        m_label->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
        auto layout = new QVBoxLayout(this);
        layout->addWidget(m_label);
        layout->setContentsMargins(0, 0, 0, 0);

        connect(this, &ShipWidget::onPressed, controller, [&]() {
            controller->ship_click(m_id);
        });
    }

    void ShipWidget::mousePressEvent(QMouseEvent *ev) {
        qDebug() << "Ship is pressed";
        emit onPressed();
    }
}
