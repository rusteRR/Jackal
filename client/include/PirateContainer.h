#ifndef JACKALUI_PIRATECONTAINER_H
#define JACKALUI_PIRATECONTAINER_H
#include <QWidget>
#include <QHBoxLayout>
#include "PirateWidget.h"
namespace jackalui{
    class PirateContainer : public QWidget{
        Q_OBJECT
    public:
        explicit PirateContainer(QWidget* parent = nullptr) : QWidget(parent), m_layout(new QHBoxLayout(this)) {
        }
    void addPirate(PirateWidget* pirateWidget){
            m_layout->addWidget(pirateWidget);
        }
    void removePirate(PirateWidget* pirateWidget){
            m_layout->removeWidget(pirateWidget);
        }
    private:
        QHBoxLayout* m_layout;
    };
}
#endif //JACKALUI_PIRATECONTAINER_H
