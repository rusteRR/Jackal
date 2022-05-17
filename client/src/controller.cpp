#include "controller.h"
#include <QHostAddress>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <iostream>

Controller::Controller(QObject *parent) : QObject(parent), m_socket(new QTcpSocket(this)) {
    m_socket->connectToHost(QHostAddress("127.0.0.1"), 4242);
    connect(m_socket, &QTcpSocket::readyRead, this, &Controller::read_response);
    in.setDevice(m_socket);
    in.setVersion(QDataStream::Qt_4_0);
}
void Controller::send_to_server(const QJsonDocument &str){
    QByteArray data;
    qDebug() << str;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_2);
    out << str;
    m_socket->write(data);
}
void Controller::send_to_server(const QJsonObject &obj) {
    send_to_server(QJsonDocument(obj));
}
void Controller::start_game() {
    QJsonObject qObj;
    qObj.insert("game", "Jackal");
    qObj.insert("request_type", "game_start");
    send_to_server(qObj);
}

void Controller::end_game() {
    std::cout << "end game!" << std::endl;
}

void Controller::pass_coords(int row, int col) {
    // TODO: this signal come from click on cell, should move into server, then perhaps open cell
    std::cout << row << " " << col << std::endl;
    //emit open_cell(row, col);

    QJsonObject qObj;
    qObj.insert("game", "Jackal");
    qObj.insert("request_type", "cell_click");
    qObj.insert("pirate_id", "1"); // TODO: actually not 1, should be different
    qObj.insert("col_to", col);
    qObj.insert("row_to", row);
    send_to_server(qObj);
}

void Controller::ship_click(int id, int row, int col) {
    std::cout << "Ship_id: " << id << std::endl;
    // emit move_ship(6, 0, 7, 0, id, 1);
    // TODO: usually waiting for response, that will move ship into other cell
    QJsonObject qObj;
    qObj.insert("game", "Jackal");
    qObj.insert("request_type", "ship_click");
    qObj.insert("pirate_id", id);
    qObj.insert("col_to", col);
    qObj.insert("row_to", row);
    send_to_server(qObj);
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
    //emit field_response(json);
    if (json["response_type"] == "game_state") {
        emit handle_field(json["field_data"].toArray());
        emit handle_players(json["players_data"].toArray());
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
    send_to_server(qObj);
}

