#include "EventWidget.h"

namespace jackalui {
    EventWidget::EventWidget(int col_, int row_, QWidget *parent, Controller *controller_) : QWidget(parent),
                                                                                             m_label(new QLabel(this)),
                                                                                             m_col(col_), m_row(row_),
                                                                                           //  money_counter(new QLabel(this)),
                                                                                             controller(controller_) {
        if (m_col == 0 || m_row == 0 || m_col == 12 || m_row == 12) {
            picture_to_set = "water.png";
        } else {
            picture_to_set = "closed.png";
        }

        QPixmap pixmap(picture_to_set);
        m_label->setScaledContents(true);
        m_label->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
        m_label->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

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
        pirate1 = new QPushButton(this);
        pirate2 = new QPushButton(this);
        pirate3 = new QPushButton(this);
        QPixmap pirate_pic("pirate_icon" + QString::number(m_player + 1) + ".png");
        QIcon ButtonIcon(pirate_pic);


        // rect.adjust(10, 10, -10, -10);
        pirate1->setFixedSize(20, 20);
        pirate1->setIcon(ButtonIcon);
        // pirate1->setIconSize(pirate1->rect().size());
        // pirate1->raise();
        QRect rect(QPoint(), pirate1->size());
        QRegion region(rect,QRegion::Ellipse);
        pirate1->setMask(region);
        pirate1->setGeometry(13, 56, 25, 25);

        pirate2->setFixedSize(20, 20);
        pirate2->setIcon(ButtonIcon);
        pirate2->setMask(region);
        pirate2->setGeometry(38, 56, 25, 25);

        pirate3->setFixedSize(20, 20);
        pirate3->setIcon(ButtonIcon);
        pirate3->setMask(region);
        pirate3->setGeometry(13, 56, 25, 25);

        /*pirate1->setGeometry(13, 56, 25, 25);
        pirate1->setIcon(ButtonIcon);
        pirate1->setIconSize(pirate1->rect().size());
        pirate1->raise();*/

        /*pirate2->setGeometry(38, 56, 25, 25);
        pirate2->setIcon(ButtonIcon);
        pirate2->setIconSize(pirate2->rect().size());
        pirate2->raise();

        pirate3->setGeometry(63, 56, 25, 25);
        pirate3->setIcon(ButtonIcon);
        pirate3->setIconSize(pirate3->rect().size());
        pirate3->raise();*/



        if (!m_have_ship) {
            pirate1->hide();
            pirate2->hide();
            pirate3->hide();
        } else {
            m_pirates_amount = 3;
        }

        // set_coins(0);

        connect(this, &EventWidget::onPressed, controller, [&]() {
            controller->pass_coords(m_player, m_row, m_col);
        });
        /*QSignalMapper mapper;

        connect(pirate1, SIGNAL(clicked()), &mapper,  SLOT(map()));
        mapper.setMapping(pirate1, 0); // Number to be passed in the slot

        connect(pirate2, SIGNAL(clicked()), &mapper, SLOT(map()));
        mapper.setMapping(pirate2, 1); // Number to be passed in the slot

        connect(pirate3, SIGNAL(clicked()), &mapper, SLOT(map()));
        mapper.setMapping(pirate3, 2); // Number to be passed in the slot

        connect(&mapper, SIGNAL(mapped(int)), this, SLOT(PirateClicked(int)));*/
        connect(pirate1, SIGNAL(clicked()),  SLOT(PirateClickedFirst()));
        connect(pirate2, SIGNAL(clicked()),  SLOT(PirateClickedSecond()));
        connect(pirate3, SIGNAL(clicked()),  SLOT(PirateClickedThird()));
    }

    void EventWidget::set_pic(const QString &file_to_set) {
        filename = file_to_set;
    }

    void EventWidget::set_ship(int player_number, int money) {
        if (m_have_ship) {
            ship->set_coins(money);
            return;
        }
        m_have_ship = true;
        layout()->removeWidget(m_label);
        ship = new ShipWidget(player_number, money, m_row, m_col, this, controller);
        layout()->addWidget(ship);
        m_is_flipped = true;
    }

    void EventWidget::set_coins(int money_count) {
        if (m_have_ship) {
            ship->set_coins(money_count);
            return;
        }
        if (!m_is_flipped) {
            return;
        }
        m_money = money_count;
        QPixmap coin("coin.png");
        QPainter painter(&coin);
        painter.setFont(QFont("Italic", 50));
        painter.drawText(45, 95, QString::number(money_count));
        QIcon ButtonIcon(coin);
        money_counter->setIcon(ButtonIcon);
        money_counter->setIconSize(money_counter->rect().size());
        if (money_count > 0) {
            money_counter->show();
            money_counter->raise();
        } else {
            money_counter->hide();
        }
    }

    void EventWidget::add_pirate(int player_id, int pirate_id) {
        m_player = player_id;
        m_pirates_amount++;
        QPixmap pirate_pic("pirate_icon" + QString::number(m_player + 1) + ".png");
        QIcon ButtonIcon(pirate_pic);
        if (pirate_id == 0) {
            pirate1->setIcon(ButtonIcon);
            pirate1->setIconSize(pirate1->rect().size());
            pirate1->show();
            pirate1->raise();
        } else if (pirate_id == 1) {
            pirate2->setIcon(ButtonIcon);
            pirate2->setIconSize(pirate2->rect().size());
            pirate2->show();
            pirate2->raise();
        } else {
            pirate3->setIcon(ButtonIcon);
            pirate3->setIconSize(pirate3->rect().size());
            pirate3->show();
            pirate3->raise();
        }
    }

    void EventWidget::remove_pirates() {
        if (m_pirates_amount == 0) return;
        m_pirates_amount = 0;
        pirate1->hide();
        pirate2->hide();
        pirate3->hide();
    }

    void EventWidget::flip() {
        if (m_is_flipped || picture_to_set == "water.png") return;

        money_counter = new QPushButton(this);
        money_counter->setGeometry(0, 0, 25, 25);

        QPixmap coin("coin.png");
        QPainter painter(&coin);
        painter.setFont(QFont("Italic", 50));
        painter.drawText(45, 95, "0");
        QIcon ButtonIcon(coin);
        money_counter->setIcon(ButtonIcon);
        money_counter->setIconSize(money_counter->rect().size());
        connect(money_counter, SIGNAL(clicked()),  SLOT(CoinClicked()));

        set_coins(0);

        m_is_flipped = true;
        QPixmap pixmap(filename);
        m_label->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
    }

    void EventWidget::removeShip() {
        layout()->removeWidget(ship);
        delete ship;
        layout()->addWidget(m_label);
        m_have_ship = false;
        m_is_flipped = false;
    }

    void EventWidget::PirateClickedFirst() {
        int pirate_id = 0;
        qDebug() << "Pirate clicked " << pirate_id;
        emit controller->pirate_click(m_player, pirate_id, m_row, m_col);
    }

    void EventWidget::PirateClickedSecond() {
        int pirate_id = 1;
        qDebug() << "Pirate clicked " << pirate_id;
        emit controller->pirate_click(m_player, pirate_id, m_row, m_col);
    }

    void EventWidget::PirateClickedThird() {
        int pirate_id = 2;
        qDebug() << "Pirate clicked " << pirate_id;
        emit controller->pirate_click(m_player, pirate_id, m_row, m_col);
    }

    void EventWidget::CoinClicked() {
        emit controller->click_coin(m_row, m_col);
    }

    void EventWidget::mousePressEvent(QMouseEvent *event) {
        qDebug() << "Pressed";
        // if (ship_num == -1) flip(); // flip should come from controller
        emit onPressed();
    }
}
