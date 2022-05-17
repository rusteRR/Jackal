#include "ShipWidget.h"

namespace jackalui {
    ShipWidget::ShipWidget(int id, int money_, int row, int col, QWidget *parent, Controller *controller_) : m_id(id), QWidget(parent),
                                                                                           m_label(new QLabel(this)),
                                                                                           money_counter(new QLabel(m_label)),
                                                                                           controller(controller_),
                                                                                           money(money_), m_row(row), m_col(col) {
        m_label->setScaledContents(true);
        QString picture_to_set = QString::fromStdString(std::string("ship" + std::to_string(id) + ".png"));
        QPixmap pixmap(picture_to_set);
        m_label->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
        auto layout = new QVBoxLayout(this);
        layout->addWidget(m_label);
        layout->setContentsMargins(0, 0, 0, 0);

        // TODO: set money counter inside ship, probably it could be more beautiful :)
        money_counter->setFrameStyle(QFrame::Panel | QFrame::Sunken);
        money_counter->setAlignment(Qt::AlignBottom);
        money_counter->setNum(money);

        connect(this, &ShipWidget::onPressed, controller, [&]() {
            controller->ship_click(m_id, m_row, m_col);
        });
    }

    void ShipWidget::set_coins(int money_count) {
        money = money_count;
        money_counter->setNum(money);
    }

    void ShipWidget::mousePressEvent(QMouseEvent *ev) {
        qDebug() << "Ship is pressed";
        emit onPressed();
    }
}
