#ifndef JACKALUI_SHIPWIDGET_H
#define JACKALUI_SHIPWIDGET_H
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>

namespace jackalui {
    class ShipWidget : public QWidget {
    Q_OBJECT
    public:
        explicit ShipWidget(QWidget* parent = nullptr) : QWidget(parent) {
            m_label->setScaledContents(true);
            QString picture_to_set = "ship1.png";
            QPixmap pixmap(picture_to_set);
            m_label->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
            auto layout = new QVBoxLayout(this);
            layout->addWidget(m_label);
            layout->setContentsMargins(0, 0, 0, 0);
        }

    public slots:
        void MoveShip() {

        }

    signals:
        void onPressed();

    private:
        QLabel* m_label;


    protected:
        void mousePressEvent(QMouseEvent *ev) override {
            emit onPressed();
        }
    };
}
#endif //JACKALUI_SHIPWIDGET_H
