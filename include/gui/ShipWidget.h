#ifndef JACKALUI_SHIPWIDGET_H
#define JACKALUI_SHIPWIDGET_H
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>

namespace jackalui {
    class ShipWidget : public QLabel {
    Q_OBJECT
    public:
        explicit ShipWidget(QWidget* parent = nullptr) : QLabel(parent) {
            this->setScaledContents(true);
            this->setPixmap(QPixmap("../pics/ship.png"));
            this->setGeometry(51,51,101,101);
        }

    public slots:
        void MoveShip() {
            this->move(this->pos().x() + 50, this->pos().y() + 50);
        }

    signals:
        void onPressed();

    protected:
        void mousePressEvent(QMouseEvent *ev) override {
            emit onPressed();
        }
    };
}
#endif //JACKALUI_SHIPWIDGET_H
