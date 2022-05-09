#ifndef JACKALUI_SHIPWIDGET_H
#define JACKALUI_SHIPWIDGET_H
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>

namespace jackalui {
    class ShipWidget : public QWidget {
    Q_OBJECT
    public:
        explicit ShipWidget(QWidget* parent = nullptr);

    public slots:
        void MoveShip() {}

    signals:
        void onPressed();

    private:
        QLabel* m_label;


    protected:
        void mousePressEvent(QMouseEvent *ev) override;
    };
}
#endif //JACKALUI_SHIPWIDGET_H
