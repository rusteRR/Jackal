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
    m_socket->flush();
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

void Controller::pass_coords(int id, int row, int col) {
    std::cout << row << " " << col << std::endl;

    QJsonObject qObj;
    qObj.insert("game", "Jackal");
    qObj.insert("request_type", "cell_click");
    qObj.insert("pirate_id", id); // TODO: actually not 1, should be different
    qObj.insert("col_to", col);
    qObj.insert("row_to", row);
    send_to_server(qObj);
}

void Controller::enter_name(const QString &name) {
    std::cout << "Name entered: " << name.toStdString() << std::endl;

    QJsonObject qObj;
    qObj.insert("game", "Jackal");
    qObj.insert("request_type", "enter_name");
    qObj.insert("name", name);
    send_to_server(qObj);
}

void Controller::back_to_menu_slot(){
    std::cout << "Back to menu" << std::endl;
    QJsonObject qObj;
    qObj.insert("game", "Jackal");
    qObj.insert("request_type", "back_to_menu");
    send_to_server(qObj);
}

void Controller::ship_click(int id, int row, int col) {
    std::cout << "Ship_id: " << id << std::endl;

    QJsonObject qObj;
    qObj.insert("game", "Jackal");
    qObj.insert("request_type", "ship_click");
    qObj.insert("pirate_id", id);
    qObj.insert("col_to", col);
    qObj.insert("row_to", row);
    send_to_server(qObj);
}

void Controller::pirate_click(int id, int row, int col) {
    std::cout << "Pirate_id: " << id << ' ' << row << ' ' << col << std::endl;

    QJsonObject qObj;
    qObj.insert("game", "Jackal");
    qObj.insert("request_type", "pirate_click");
    qObj.insert("pirate_id", id);
    qObj.insert("col_to", col);
    qObj.insert("row_to", row);
    send_to_server(qObj);
}


void Controller::read_response() {
    qDebug() << "entered read_response";
    in.startTransaction();
    QJsonDocument json;
    while (!in.atEnd()) {
        in >> json;
        //emit field_response(json);
        qDebug() << "response_type is " << json["response_type"];
        if (json["response_type"] == "game_state") {
            emit handle_field(json["field_data"].toArray());
            emit handle_players(json["players_data"].toArray());
            return;
        }
        else if (json["response_type"] == "confirm_registration") {
            emit authCorrect();
            return;
        }
        else if (json["response_type"] == "requests_error") {
            /* emit handle_error(json["error"])  */
        }
        else if (json["response_type"] == "players"){
            //TODO: show names
        } else{
            qDebug() << "unknown response";
        }
    }
    if (!in.commitTransaction())
        return;
    if (in.status() != QDataStream::Ok) {
        return;
    }
}

