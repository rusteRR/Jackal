#include "thread.h"

namespace jackal {
    ClientThread::ClientThread(int socketDescription, QObject *parent) {
        m_socket = new QTcpSocket(this);
        if (!m_socket->setSocketDescriptor(socketDescription)) {
            emit error(m_socket->error());
        }
        connect(m_socket, &QTcpSocket::readyRead, this, &ClientThread::read_response);
        connect(m_socket, &QTcpSocket::disconnected, this, &ClientThread::disconnect_response);
    }

    void ClientThread::run() {
        exec();
    }

    void ClientThread::produce_json(QJsonObject &jsonObject) {
        QString request_type(jsonObject.value("request_type").toString());
        if (request_type == "game_start") {
            emit game_start();
        } else if (request_type == "get_filename") {
            int row = jsonObject.value("row").toInt();
            int col = jsonObject.value("col").toInt();
            Field field;
            emit get_field(field);
            std::string filename = field.get_element(col, row).get_filename();
        }
    }

    void ClientThread::send_to_client(const QJsonDocument &str, QTcpSocket *socket) {
        m_data.clear();
        qDebug() << str;
        QDataStream out(&m_data, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_2);
        out << str;
        socket->write(m_data);
    }

    void ClientThread::read_response() {
        QByteArray Data = m_socket->readAll();
        qDebug() << Data;
        QJsonObject json;
        Field field;
        emit get_field(field);
        //auto field = m_game->get_field();
        for (int i = 0; i < 13; ++i) {
            for (int j = 0; j < 13; ++j) {
                json.insert((std::to_string(j) + ' ' + std::to_string(i)).c_str(),
                            field.get_element(j, i).get_filename().c_str());
            }
        }
        send_to_client(QJsonDocument(json), m_socket);
    }

    void ClientThread::disconnect_response() {
        m_socket->close();
        exit(0);
    }
}