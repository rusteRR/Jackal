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
        explicit ShipWidget(int id, int money_, QWidget *parent = nullptr, Controller *controller_ = nullptr);

    public slots:

        void MoveShip() {}

    signals:

        void onPressed();

    private:
        QLabel *m_label;
        int m_id;
        int money;
        Controller *controller;

    protected:
        void mousePressEvent(QMouseEvent *ev) override;
    };
}
#endif //JACKALUI_SHIPWIDGET_H
