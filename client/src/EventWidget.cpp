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
            set_ship(0, 0);
            m_player = 0;
        } else if (m_row == 6 && m_col == 12) {
            set_ship(1, 0);
            m_player = 1;
        } else if (m_row == 12 && m_col == 6) {
            set_ship(2, 0);
            m_player = 2;
        } else if (m_row == 6 && m_col == 0) {
            set_ship(3, 0);
            m_player = 3;
        }
        pirate = new QPushButton(this);
        QPixmap pirate_pic("pirate3.png");
        QIcon ButtonIcon(pirate_pic);
        pirate->setGeometry(45, 42, 40, 40);
        pirate->setIcon(ButtonIcon);
        pirate->setIconSize(pirate->rect().size());
        pirate->raise();

        if (!have_ship) {
            pirate->hide();
        } else {
            pirates_amount = 3;
        }

        connect(this, &EventWidget::onPressed, controller, [&]() {
            controller->pass_coords(m_player, m_row, m_col);
        });

        connect(pirate, SIGNAL(clicked()),  SLOT(PirateClicked()));
    }

    void EventWidget::set_pic(const QString &file_to_set) {
        filename = file_to_set;
    }

    void EventWidget::set_ship(int player_number, int money) {
        if (have_ship) return;
        have_ship = true;
        layout()->removeWidget(m_label);
        ship = new ShipWidget(player_number, money, m_row, m_col, this, controller);
        layout()->addWidget(ship);
        m_is_flipped = true;
    }

    void EventWidget::add_pirate(int player_id) {
        pirates_amount++;
        QPixmap pirate_pic(QString::fromStdString("pirate" + std::to_string(pirates_amount) + ".png"));
        QIcon ButtonIcon(pirate_pic);
        pirate->setIcon(ButtonIcon);
        pirate->setIconSize(pirate->rect().size());
        pirate->show();
        pirate->raise();
        m_player = player_id;
    }

    void EventWidget::remove_pirates() {
        if (pirates_amount == 0) return;
        pirates_amount = 0;
        pirate->hide();
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
        have_ship = false;
    }

    void EventWidget::PirateClicked() {
        emit controller->pirate_click(m_player, m_row, m_col);
    }

    void EventWidget::mousePressEvent(QMouseEvent *event) {
        qDebug() << "Pressed";
        // if (ship_num == -1) flip(); // flip should come from controller
        emit onPressed();
    }
}
