#include "thread.h"

namespace jackal {
    ClientWorker::ClientWorker(int socketDescription, int thread_id, QObject *parent) : QObject(parent),
                                                                                        m_socket_description(
                                                                                                socketDescription),
                                                                                        m_thread_id(thread_id) {
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
            qDebug() << "Process registration: " << name;
            emit register_player(name, m_thread_id);
            return;
        }
        if (request_type == "back_to_menu"){
            qDebug() << "back to menu";
            emit quit(m_player_id);
        }
        if (!is_my_turn){
            qDebug() << "not my turn:" << m_player_id;
            return;
        }
        if (m_ship_clicked) {
            if (request_type != "cell_click") {
                send_error("not cell clicked");
                return;
            }
            qDebug() << "ship_move"; // TODO: need pass correct pirate id
            emit process_move("ship_move", 0, json["col_to"].toInt(), json["row_to"].toInt());
            m_ship_clicked = false;
            is_my_turn = false;
        }
        else if (m_pirate_clicked) {
            if (request_type != "cell_click" && request_type != "ship_click") {
                send_error("not cell nor ship clicked");
                return;
            }
            qDebug() << "pirate_move";
            emit process_move("pirate_move", 0, json["col_to"].toInt(),
                              json["row_to"].toInt());
            qDebug() << "pirate_move successful";
            m_pirate_clicked = false;
            is_my_turn = false;
        }
        else if (request_type == "ship_click") {
            m_ship_clicked = true;
        } else if (request_type == "pirate_click") {
            if (json["pirate_id"].toInt() == m_player_id){
                m_pirate_clicked = true;
            }
        }
    }

    void ClientWorker::send_to_client(const QJsonDocument &str) {
        qDebug() << "send data to client";
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
        error.insert("response_type", "requests_error");
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

    void ClientWorker::send_json_slot(QJsonObject json) {
        send_to_client(json);
    }

    void ClientWorker::disconnect_response() {
        m_socket->close();
        qDebug() << "disconnected";
        emit quit(m_player_id);
        emit finish();
    }

    void ClientWorker::confirm_registration_slot(int player_id, int sender_id) {
        if (m_thread_id != sender_id) {
            return;
        }
        if (player_id == -1) {
            qDebug() << "registration requested";
            return;
        }
        qDebug() << "player's id:" << player_id << ", registration confirmed";
        m_player_id = player_id;
        QJsonObject confirm_registration;
        confirm_registration.insert("game", "jackal");
        confirm_registration.insert("response_type", "confirm_registration");
        send_to_client(confirm_registration);
    }
    void ClientWorker::update_status_slot(int id) {
        qDebug() << "Now moving:" << id;
        if (m_player_id == id) is_my_turn = true;
        else is_my_turn = false;
    }
}
