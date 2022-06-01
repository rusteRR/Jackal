#ifndef JACKALUI_EVENTWIDGET_H_
#define JACKALUI_EVENTWIDGET_H_

#include <QLabel>
#include <QDebug>
#include <QGridLayout>
#include <QString>
#include <QPushButton>
#include "PirateWidget.h"
#include "controller.h"
#include "ShipWidget.h"
#include <string>

namespace jackalui {
    class EventWidget : public QWidget {
    Q_OBJECT
    public:
        explicit EventWidget(int col_, int row_, QWidget *parent = nullptr, Controller *controller_ = nullptr);

        void set_pic(const QString &file_to_set);

        void set_ship(int player_number, int money);

        void flip();

        void removeShip();

        void add_pirate(int player_id);

        void remove_pirates();

    private:
        QLabel *m_label;
        Controller *controller;
        QString filename;
        QString picture_to_set;
        ShipWidget *ship;
        // TODO: PirateWidget *pirate;
        QPushButton *pirate;
        bool m_is_flipped = false;
        int m_col, m_row;
        int pirates_amount = 0;
        int m_player;
        bool have_ship = false;

    public slots:

        void PirateClicked();

    signals:

        void onPressed();

    protected:
        void mousePressEvent(QMouseEvent *event) override;

    };
}
#endif // JACKALUI_EVENTWIDGET_H_
