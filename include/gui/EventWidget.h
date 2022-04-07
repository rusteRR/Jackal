#ifndef JACKALUI_EVENTWIDGET_H_
#define JACKALUI_EVENTWIDGET_H_

#include <QLabel>
#include <QDebug>
#include <QGridLayout>
#include <QString>
#include "PirateContainer.h"
#include "event.h"
#include <string>

namespace jackalui {
    class EventWidget : public QWidget {
    Q_OBJECT
    public:
        explicit EventWidget(int col_, int row_, jackal::Event& event, QWidget *parent = nullptr) : QWidget(parent),
                                                                              m_label(new QLabel(this)),
                                                                              m_pirateContainer(
                                                                                      new PirateContainer(this)),
                                                                              m_col(col_), m_row(row_) {
            m_label->setScaledContents(true);
            filename = event.get_filename();
            if (event.get_filename() == "water.png") {
                QPixmap pixmap("water.png");
                m_label->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
            }
            else {
                QPixmap pixmap("closed.png");
                m_label->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
            }
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
        
        [[nodiscard]] int row() const{
            return m_row;
        }
        
        [[nodiscard]] int col() const{
            return m_col;
        }
        
    private:
        void flip() {
            if (m_is_flipped) return;
            m_is_flipped = true;
            QPixmap pixmap(filename.c_str());
            m_label->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
        }

        QLabel *m_label;
        std::string filename;
        bool m_is_flipped = false;
        PirateContainer *m_pirateContainer;
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
