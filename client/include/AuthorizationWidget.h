#ifndef JACKAL_AUTHORIZATIONWIDGET_H
#define JACKAL_AUTHORIZATIONWIDGET_H


#include <QWidget>
#include <QDialog>
#include <QBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QDebug>
#include <QMainWindow>
#include <QMessageBox>
#include <QGridLayout>
#include <QApplication>
#include "ExitLabel.h"
#include "controller.h"
#include "GameStartLabel.h"

namespace jackalui {
    class AuthorizationWidget : public QDialog {
    Q_OBJECT
    public:
        explicit AuthorizationWidget(QWidget* parent = nullptr, Controller *controller_ = nullptr) : QDialog(parent), controller(controller_) {
            //this->setStyleSheet( "background-color: rgb(176, 174, 114);");
            this->setStyleSheet( "background-image: url(error_background.png);");
            resize(400, 130);
            setWindowTitle("Jackal");

            QBoxLayout* layout = new QHBoxLayout;
            m_edit = new QLineEdit;
            layout->addWidget( m_edit );
            m_edit->setPlaceholderText("Enter your name:");

            auto okBtn = new QPushButton( "OK" );
            connect( okBtn, SIGNAL( clicked() ), SLOT( accept() ) );
            layout->addWidget( okBtn );
            setLayout( layout );
        }

        QString getInput() const {
            return m_edit->text();
        }

    public slots:
        void accept() {
            emit controller->enter_name(m_edit->text());
        }


    private:
        QLineEdit* m_edit;
        Controller* controller;
    };
}

#endif //JACKAL_AUTHORIZATIONWIDGET_H
