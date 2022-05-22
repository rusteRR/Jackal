#include "thread.h"

namespace jackal {
    ClientWorker::ClientWorker(int socketDescription, int player, QObject *parent) : QObject(parent),
                                                                                     m_socket_description(
                                                                                             socketDescription),
                                                                                     player_id(player) {
        m_socket = new QTcpSocket(this);
        if (!m_socket->setSocketDescriptor(m_socket_description)) {
            emit error(m_socket->error());
            return;
        }
        connect(m_socket, &QTcpSocket::readyRead, this, &ClientWorker::read_response);
        connect(m_socket, &QTcpSocket::disconnected, this, &ClientWorker::disconnect_response);
    }

    void ClientWorker::produce_json(QJsonDocument &json) {
        qDebug() << "produce_json";
        QString request_type = json["request_type"].toString();
        qDebug() << request_type;
        if (request_type == "game_start") {
            emit authentication();
            emit game_start();
            return;
        }
        qDebug() << 1;
        emit update_my_turn(player_id);
        qDebug() << 1;
        if (!my_turn){
            return;
        }
        if (ship_clicked) {
            if (request_type != "cell_click") {
                send_error("not cell clicked");
                return;
            }
            qDebug() << "cell_click";
            emit process_move("ship_move", json["pirate_id"].toInt(), json["col_to"].toInt(), json["row_to"].toInt());
            ship_clicked = false;
        }
        if (pirate_clicked_id != -1) {
            if (request_type != "cell_click" && request_type != "ship_click") {
                send_error("not cell nor ship clicked");
                return;
            }
            emit process_move(request_type, json["pirate_id"].toInt(), json["col_to"].toInt(),
                              json["row_to"].toInt());
            pirate_clicked_id = -1;
        }
        if (request_type == "ship_click") {
            ship_clicked = true;
        } else if (request_type == "pirate_click") {
            pirate_clicked_id = json["pirate_id"].toInt();
        }
        qDebug() << 1;
    }

    void ClientWorker::send_to_client(const QJsonDocument &str) {
        QByteArray data;
        qDebug() << str;
        QDataStream out(&data, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_2);
        out << str;
        m_socket->write(data);
    }

    void ClientWorker::send_to_client(const QJsonObject &obj) {
        send_to_client(QJsonDocument(obj));
    }

    void ClientWorker::send_error(const QString &str) {
        QJsonObject error;
        error.insert("game", "Jackal");
        error.insert("request_type", "requests_error");
        error.insert("error", str);
        send_to_client(error);
    }

    void ClientWorker::read_response() {
        in.setDevice(m_socket);
        in.setVersion(QDataStream::Qt_4_0);
        QJsonDocument json;
        while (!in.atEnd()) {
            qDebug() << 1;
            in.startTransaction();
            in >> json;
            qDebug() << json;
            if (!in.commitTransaction())
                return;
            if (in.status() != QDataStream::Ok) {
                return;
            }
            produce_json(json);
        }
    }

    void ClientWorker::json_response(QJsonObject json) {
        send_to_client(json);
    }
    
    void ClientWorker::update_turn_response(bool is_my_turn) {
        my_turn = is_my_turn;
    }

    void ClientWorker::disconnect_response() {
        m_socket->close();
        qDebug() << "disconnected";
        emit finish();
    }
}
