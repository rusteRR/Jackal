#ifndef JACKALUI_EVENTWIDGET_H_
#define JACKALUI_EVENTWIDGET_H_

#include <QLabel>
#include <QDebug>
#include <QGridLayout>
#include <QString>
#include "PirateContainer.h"
#include "event.h"
#include "game.h"
#include "contoller.h"
#include <string>

namespace jackalui {
    class EventWidget : public QWidget {
    Q_OBJECT
    public:
        explicit EventWidget(int col_, int row_, QWidget *parent = nullptr, Controller* controller_ = nullptr);
        
        void set_pic(const QString& file_to_set);

        void set_ship(int player_number);

        void flip();
        
    private:
        QLabel* m_label;
        Controller* controller;
        QString filename;
        QString picture_to_set;
        bool m_is_flipped = false;
        int m_col, m_row;
        int ship_num = -1;

    signals:
        void onPressed();

    protected:
        void mousePressEvent(QMouseEvent *event) override;

    };
}
#endif // JACKALUI_EVENTWIDGET_H_
