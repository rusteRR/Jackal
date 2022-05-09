#include "EventWidget.h"

namespace jackalui {
    EventWidget::EventWidget(int col_, int row_, QWidget *parent, Controller *controller_) : QWidget(parent),
                                                                                             m_label(new QLabel(this)),
                                                                                             m_col(col_), m_row(row_),
                                                                                             controller(controller_) {
        if (m_col == 0 || m_row == 0 || m_col == 12 || m_row == 12) {
            picture_to_set = "water.png";
        } else {
            picture_to_set = "closed.png";
        }
        QPixmap pixmap(picture_to_set);
        m_label->setScaledContents(true);
        m_label->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));

        auto layout = new QVBoxLayout(this);
        layout->addWidget(m_label);
        layout->setContentsMargins(0, 0, 0, 0);

        if (m_row == 0 && m_col == 6) {
            set_ship(0);
        } else if (m_row == 6 && m_col == 12) {
            set_ship(1);
        } else if (m_row == 12 && m_col == 6) {
            set_ship(2);
        } else if (m_row == 6 && m_col == 0) {
            set_ship(3);
        }

        connect(this, &EventWidget::onPressed, controller, [&]() {
            controller->pass_coords(m_row, m_col);
        });
    }

    void EventWidget::set_pic(const QString &file_to_set) {
        filename = file_to_set;
    }

    void EventWidget::set_ship(int player_number) {
        layout()->removeWidget(m_label);
        ship = new ShipWidget(player_number, this, controller);
        layout()->addWidget(ship);
    }

    void EventWidget::flip() {
        if (m_is_flipped) return;
        m_is_flipped = true;
        QPixmap pixmap(filename);
        m_label->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
    }

    void EventWidget::removeShip() {
        layout()->removeWidget(ship);
        delete ship;
        layout()->addWidget(m_label);
    }

    void EventWidget::mousePressEvent(QMouseEvent *event) {
        qDebug() << "Pressed";
        // if (ship_num == -1) flip(); // flip should come from controller
        emit onPressed();
    }
}
