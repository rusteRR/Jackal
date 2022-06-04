#include "ShipWidget.h"

namespace jackalui {
    ShipWidget::ShipWidget(int id, int money_, int row, int col, QWidget *parent, Controller *controller_) : m_id(id), QWidget(parent),
                                                                                           m_label(new QLabel(this)),
                                                                                           controller(controller_),
                                                                                           money(money_), m_row(row), m_col(col) {
        m_label->setScaledContents(true);
        QString picture_to_set = QString::fromStdString(std::string("ship" + std::to_string(id) + ".png"));
        QPixmap pixmap(picture_to_set);
        m_label->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
        auto layout = new QVBoxLayout(this);
        layout->addWidget(m_label);
        layout->setContentsMargins(0, 0, 0, 0);


        money_counter = new QPushButton(this);
        money_counter->setGeometry(0, 0, 25, 25);

        QPixmap coin("coin.png");
        QPainter painter(&coin);
        painter.setFont(QFont("Italic", 50));
        painter.drawText(45, 95, "0");
        QIcon ButtonIcon(coin);
        money_counter->setIcon(ButtonIcon);
        money_counter->setIconSize(money_counter->rect().size());

        connect(this, &ShipWidget::onPressed, controller, [&]() {
            controller->ship_click(m_id, m_row, m_col);
        });
    }

    void ShipWidget::set_coins(int money_count) {
        money = money_count;

        QPixmap coin("coin.png");
        QPainter painter(&coin);
        painter.setFont(QFont("Italic", 50));
        painter.drawText(45, 95, QString::number(money));
        QIcon ButtonIcon(coin);
        money_counter->setIcon(ButtonIcon);
        money_counter->setIconSize(money_counter->rect().size());
    }

    void ShipWidget::mousePressEvent(QMouseEvent *ev) {
        qDebug() << "Ship is pressed";
        emit onPressed();
    }
}
