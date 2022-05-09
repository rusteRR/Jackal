#include "contoller.h"
#include <QHostAddress>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <iostream>

Controller::Controller(QObject *parent) : QObject(parent), m_socket(new QTcpSocket(this)) {
    m_socket->connectToHost(QHostAddress("127.0.0.1"), 4242);
    connect(m_socket, &QTcpSocket::readyRead, this, &Controller::read_response);
    in.setDevice(m_socket);
    in.setVersion(QDataStream::Qt_4_0);
}

void Controller::start_game() {
    QJsonObject qObj;
    qObj.insert("game", "Jackal");
    qObj.insert("request_type", "game_start");
    m_socket->write(QJsonDocument(qObj).toJson());
}

void Controller::end_game() {
    std::cout << "end game!" << std::endl;
}

void Controller::pass_coords(int col, int row) {
    std::cout << col << " " << row << std::endl;
    emit open_cell(row, col);
}

void Controller::read_response() {
    in.startTransaction();
    QJsonDocument str;
    in >> str;
    if (!in.commitTransaction())
        return;
    if (in.status() == QDataStream::Ok) {
        emit field_response(str);
    }
}

void Controller::wait_filename() {
    QJsonObject qObj;
    qObj.insert("game", "Jackal");
    qObj.insert("request_type", "get_filename");
    m_socket->write(QJsonDocument(qObj).toJson());
}

