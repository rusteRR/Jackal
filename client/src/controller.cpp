#include "contoller.h"
#include <QHostAddress>
#include <QJsonDocument>
#include <QJsonObject>
#include <iostream>

Controller::Controller(QObject *parent) : QObject(parent), m_socket(this) {
    m_socket.connectToHost(QHostAddress("127.0.0.1"), 4242);
    connect(&m_socket, &QTcpSocket::readyRead, this, &Controller::on_ready_read);
}

void Controller::start_game() {
    QJsonObject qObj;
    qObj.insert("game", "Jackal");
    qObj.insert("request_type", "game_start");
    m_socket.write(QJsonDocument(qObj).toJson());
}

void Controller::end_game() {
    std::cout << "end game!" << std::endl;
}

void Controller::on_ready_read() {
    return;
}

