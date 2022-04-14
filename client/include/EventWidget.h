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
         explicit EventWidget(int col_, int row_, QWidget *parent = nullptr, Controller* controller_ = nullptr) : QWidget(parent),
                                                                              m_label(new QLabel(this)),
                                                                              m_col(col_), m_row(row_),
                                                                              controller(controller_) {
            m_label->setScaledContents(true);
            QString picture_to_set;
            if (m_col == 0 || m_row == 0 || m_col == 12 || m_row == 12) {
                picture_to_set = "water.png";
            }
            else {
                picture_to_set = "closed.png";
            }
            QPixmap pixmap(picture_to_set);
            m_label->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
            connect(this, &EventWidget::onPressed, controller, [&]() {
                controller->pass_coords(m_col, m_row);
            });
            auto layout = new QVBoxLayout(this);
            layout->addWidget(m_label);
            layout->setContentsMargins(0, 0, 0, 0);
        }
        
        void set_pic(const QString& file_to_set) {
            filename = file_to_set;
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
#endif // JACKALUI_EVENTWIDGET_H_
