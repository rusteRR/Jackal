#ifndef JACKALUI_EVENTWIDGET_H_
#define JACKALUI_EVENTWIDGET_H_

#include <QLabel>
#include <QDebug>
#include <QGridLayout>
#include <QString>
#include "PirateContainer.h"
#include "event.h"
#include "contoller.h"
#include <string>

namespace jackalui {
    class EventWidget : public QWidget {
    Q_OBJECT
    public:
         EventWidget(int col_, int row_, QWidget *parent = nullptr, Controller* controller_ = nullptr) : QWidget(parent),
                                                                              m_label(new QLabel(this)),
                                                                              m_pirateContainer(
                                                                                      new PirateContainer(this)),
                                                                              m_col(col_), m_row(row_),
                                                                              controller(controller_) {
            m_label->setScaledContents(true);
            QPixmap pixmap("closed.png");
            m_label->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
            connect(this, &EventWidget::onPressed, controller, [&]() {
                controller->pass_coords(m_col, m_row);
            });
            auto layout = new QVBoxLayout(this);
            layout->addWidget(m_label);
            layout->setContentsMargins(0, 0, 0, 0);
        }

        void addPirate(PirateWidget *pirateWidget) {
            m_pirateContainer->addPirate(pirateWidget);
        }

        void removePirate(PirateWidget *pirateWidget) {
            m_pirateContainer->removePirate(pirateWidget);
        }
        
        void set_pic(QString file) {
            filename = file;
        }
        
    private:
        void flip() {
            if (m_is_flipped) return;
            m_is_flipped = true;
            QPixmap pixmap(filename);
            m_label->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
        }

        QLabel* m_label;
        Controller* controller;
        QString filename;
        bool m_is_flipped = false;
        PirateContainer* m_pirateContainer;
        int m_col, m_row;


    signals:

        void onPressed();

    protected:
        void mousePressEvent(QMouseEvent *event) override {
            qDebug() << "Pressed";
            flip();
            emit onPressed();
        }

    };
}
#endif //JACKALUI_EVENTWIDGET_H_
