#include "controller.h"
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

void Controller::pass_coords(int row, int col) {
    // TODO: this signal come from click on cell, should move into server, then perhaps open cell
    std::cout << row << " " << col << std::endl;
    emit open_cell(row, col);
}

void Controller::ship_click(int id) {
    std::cout << "Ship_id: " << id << std::endl;
    // emit move_ship(6, 0, 7, 0, id);
    // TODO: usually waiting for response, that will move ship into other cell
}

void Controller::read_response() {
    in.startTransaction();
    QJsonDocument json;
    in >> json;
    if (!in.commitTransaction())
        return;
    if (in.status() != QDataStream::Ok) {
        return;
    }
    if (json["response_type"] == "game_state") {
        /* emit handle_field(json["field_data"]); */
        /* emit handle_players(json["players_data"]); */
        return;
    }
    if (json["response_type"] == "requests_error") {
        /* emit handle_error(json["error"])  */
    }
}

void Controller::wait_filename() {
    //
    QJsonObject qObj;
    qObj.insert("game", "Jackal");
    qObj.insert("request_type", "get_filename");
    m_socket->write(QJsonDocument(qObj).toJson());
}

