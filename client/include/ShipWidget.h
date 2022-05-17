#ifndef JACKALUI_SHIPWIDGET_H
#define JACKALUI_SHIPWIDGET_H

#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>
#include "controller.h"

namespace jackalui {
    class ShipWidget : public QWidget {
    Q_OBJECT
    public:
        explicit ShipWidget(int id, int money_, int row, int col, QWidget *parent = nullptr, Controller *controller_ = nullptr);

    public slots:

        void MoveShip() {}

        void set_coins(int money_count);

    signals:

        void onPressed();

    private:
        QLabel *m_label;
        QLabel *money_counter;
        int m_id;
        int m_row;
        int m_col;
        int money;
        Controller *controller;

    protected:
        void mousePressEvent(QMouseEvent *ev) override;
    };
}
#endif //JACKALUI_SHIPWIDGET_H
