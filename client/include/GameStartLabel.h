#ifndef JACKALUI_GAMESTARTLABEL_H
#define JACKALUI_GAMESTARTLABEL_H
#include <QLabel>
#include <QVBoxLayout>
namespace jackalui{
    class GameStartLabel : public QLabel {
        Q_OBJECT
    public:
        explicit GameStartLabel(QWidget* parent = nullptr) : QLabel(parent){
            this->setScaledContents(true);
            QPixmap pixmap("startButton.png");
            this->setPixmap(pixmap.scaled(1000,200, Qt::KeepAspectRatio));
        }
    signals:
        void onPressed();
    protected:
        void mousePressEvent(QMouseEvent *ev) override {
            emit onPressed();
        }
    };
}
#endif //JACKALUI_GAMESTARTLABEL_H
