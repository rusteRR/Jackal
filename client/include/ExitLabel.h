#ifndef JACKALUI_EXITLABEL_H
#define JACKALUI_EXITLABEL_H
#include <QLabel>
#include <QVBoxLayout>
namespace jackalui{
    class ExitLabel : public QLabel {
        Q_OBJECT
    public:
        explicit ExitLabel(QWidget* parent = nullptr) : QLabel(parent) {
            this->setScaledContents(true);
            QPixmap pixmap("exitButton.png");
            this->setPixmap(pixmap.scaled(1000, 200, Qt::KeepAspectRatio));
        }
    signals:
        void onPressed();
    protected:
        void mousePressEvent(QMouseEvent *ev) override{
            emit onPressed();
        }
    };
}
#endif //JACKALUI_EXITLABEL_H
