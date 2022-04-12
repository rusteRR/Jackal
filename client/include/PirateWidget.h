#ifndef JACKALUI_PIRATEWIDGET_H
#define JACKALUI_PIRATEWIDGET_H
#include <QLabel>
namespace jackalui{
    class PirateWidget : public QLabel{
        Q_OBJECT
    public:
        explicit PirateWidget(QWidget* parent = nullptr) : QLabel(parent) {
            this->setScaledContents(true);
            this->setPixmap(QPixmap("pirate.png"));
            this->setGeometry(0,0,50,50);
        }
    };
}
#endif //JACKALUI_PIRATEWIDGET_H
