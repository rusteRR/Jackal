#include "thread.h"

namespace jackal {
    ClientWorker::ClientWorker(int socketDescription, int player, QObject *parent) : QObject(parent),
                                                                                     m_socket_description(
                                                                                             socketDescription),
                                                                                     m_player_id(player) {
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
            emit game_start();
            return;
        }
        if (request_type == "enter_name") {
            QString name = json["name"].toString();
            qDebug() << "Registered: " << name;
            emit register_player(name, m_player_id);
            return;
        }
        /*emit update_my_turn(player_id);
        if (!my_turn){
            qDebug() << "Not my turn";
            return;
        }*/
        if (m_ship_clicked) {
            if (request_type != "cell_click") {
                send_error("not cell clicked");
                return;
            }
            qDebug() << "cell_click";
            emit process_move("ship_move", json["pirate_id"].toInt(), json["col_to"].toInt(), json["row_to"].toInt());
            m_ship_clicked = false;
        }
        if (m_pirate_clicked_id != -1) {
            if (request_type != "cell_click" && request_type != "ship_click") {
                send_error("not cell nor ship clicked");
                return;
            }
            emit process_move(request_type, json["pirate_id"].toInt(), json["col_to"].toInt(),
                              json["row_to"].toInt());
            m_pirate_clicked_id = -1;
        }
        if (request_type == "ship_click") {
            m_ship_clicked = true;
        } else if (request_type == "pirate_click") {
            m_pirate_clicked_id = json["pirate_id"].toInt();
        }
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
        m_in.setDevice(m_socket);
        m_in.setVersion(QDataStream::Qt_4_0);
        QJsonDocument json;
        while (!m_in.atEnd()) {
            m_in.startTransaction();
            m_in >> json;
            if (!m_in.commitTransaction())
                return;
            if (m_in.status() != QDataStream::Ok) {
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

    void ClientWorker::confirm_registration_slot(int id, int sender_id) {
        if (m_player_id != sender_id) {
            return;
        }
        qDebug() << "user's id:" << id << ", registration confirmed";
        m_player_id = id;
        QJsonObject confirm_registration;
        confirm_registration.insert("game", "jackal");
        confirm_registration.insert("request_type", "confirm_registration");
        send_to_client(confirm_registration);
    }
}
