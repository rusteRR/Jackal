#ifndef JACKALUI_EVENTWIDGET_H_
#define JACKALUI_EVENTWIDGET_H_
#include <QLabel>
#include <QDebug>
#include <QGridLayout>
class EventWidget : public QWidget {
    Q_OBJECT
public:
    EventWidget() {
        auto lbl = new QLabel(this);
        lbl->setPixmap(QPixmap("..//pics//test.png"));
        auto layout = new QVBoxLayout(this);
        layout->addWidget(lbl);
    }
    int kek = 0;
private:

signals:
    void onPressed(EventWidget*);

protected:
    void mousePressEvent(QMouseEvent *event) override {
        qDebug() << "Pressed";
        emit onPressed(this);
    }
};

#endif //JACKALUI_EVENTWIDGET_H_
