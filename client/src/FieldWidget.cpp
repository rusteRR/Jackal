#include "FieldWidget.h"

namespace jackalui {
    FieldWidget::FieldWidget(Controller *controller_, QWidget *parent) : QWidget(parent), controller(controller_),
                                                                         field(13) {
        auto menuButton = new QPushButton("Menu", this);
        connect(controller, &Controller::field_response, this, &FieldWidget::set_pics);
        connect(menuButton, &QPushButton::pressed, this, &FieldWidget::menuButtonPressed);
        connect(controller, &Controller::open_cell, this, &FieldWidget::cellIsOpen);
        menuButton->setMaximumSize(300, 500);
        auto grid = new QGridLayout(this);
        grid->setContentsMargins(410, 10, 410, 10);
        for (int i = 0; i < 13; ++i) {
            for (int j = 0; j < 13; ++j) {
                auto event = new EventWidget(j, i, this, controller);
                field[i].push_back(event);
                grid->addWidget(event, i, j);
            }
        }
        grid->setHorizontalSpacing(0);
        grid->setVerticalSpacing(0);

        controller->wait_filename();
    }

    void FieldWidget::set_pics(const QJsonDocument &json)  {
        qDebug() << json;
        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 13; j++) {
                QString indexes = QString::fromStdString(std::to_string(i) + " " + std::to_string(j));
                field[i][j]->set_pic(json.object().value(indexes).toString());
            }
        }
    }

    void FieldWidget::cellIsOpen(int row, int col) {
        field[row][col]->flip();
    }
}
