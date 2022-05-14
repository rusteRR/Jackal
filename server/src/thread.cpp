#include "thread.h"
#include <QHostAddress>

namespace jackal {
    ClientThread::ClientThread(int socketDescription, QObject *parent) : QThread(parent),
                                                                         m_socket_description(socketDescription) {
    }

    void ClientThread::run() {
        m_socket = new QTcpSocket();
        if (!m_socket->setSocketDescriptor(m_socket_description)) {
            emit error(m_socket->error());
            return;
        }
        connect(m_socket, &QTcpSocket::readyRead, this, &ClientThread::read_response);
        connect(m_socket, &QTcpSocket::disconnected, this, &ClientThread::disconnect_response);
        exec();
    }

    void ClientThread::produce_json(QJsonDocument &json) {
        QString request_type = json["request_type"].toString();
        qDebug() << request_type;
        if (ship_clicked) {
            if (request_type != "cell_click") {
                send_error("not cell clicked");
                return;
            }
            QJsonObject result;
            emit process_move("ship_move", json["pirate_id"].toInt(), json["col_to"].toInt(), json["row_to"].toInt(),
                              result);
            send_to_client(result);
            ship_clicked = false;
        }
        if (pirate_clicked_id != -1) {
            if (request_type != "cell_click" && request_type != "ship_click") {
                send_error("not cell nor ship clicked");
                return;
            }
            QJsonObject result;
            emit process_move(request_type.toStdString(), json["pirate_id"].toInt(), json["col_to"].toInt(),
                              json["row_to"].toInt(), result);
            send_to_client(result);
            if (result["response_type"] == "requests_error") {
                qDebug() << result["error"];
                return;
            }
            pirate_clicked_id = -1;
        }
        if (request_type == "game_start") {
            emit game_start();
        } else if (request_type == "ship_click") {
            ship_clicked = true;
        } else if (request_type == "pirate_click") {
            pirate_clicked_id = json["pirate_id"].toInt();
        }
    }

    void ClientThread::send_to_client(const QJsonDocument &str) {
        QByteArray data;
        qDebug() << str;
        QDataStream out(&data, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_2);
        out << str;
        qDebug() << 1;
        m_socket->write(data);
        qDebug() << data;
        qDebug() << 1;
    }

    void ClientThread::send_to_client(const QJsonObject &obj) {
        send_to_client(QJsonDocument(obj));
    }

    void ClientThread::send_error(const QString &str) {
        QJsonObject error;
        error.insert("game", "Jackal");
        error.insert("request_type", "requests_error");
        error.insert("error", str);
        send_to_client(error);
    }

    void ClientThread::read_response() {
        in.setDevice(m_socket);
        in.setVersion(QDataStream::Qt_4_0);
        QJsonDocument json;
        in.startTransaction();
        in >> json;
        qDebug() << json;
        if (!in.commitTransaction())
            return;
        if (in.status() != QDataStream::Ok) {
            return;
        }
        produce_json(json);
        QJsonObject json1;
        Field field;
        qDebug() << 2;
        emit get_field(field);
        qDebug() << 2;
        for (int i = 0; i < 13; ++i) {
            for (int j = 0; j < 13; ++j) {
                json1.insert((std::to_string(j) + ' ' + std::to_string(i)).c_str(),
                             field.get_element(j, i).get_filename().c_str());
            }
        }
        send_to_client(json1);
    }

    void ClientThread::disconnect_response() {
        m_socket->close();
        qDebug() << "disconnected";
        exit(0);
    }
}