#include "server.h"

namespace jackal {
    MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent) {
        m_TcpServer = new QTcpServer(this);

        connect(m_TcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

        if (!m_TcpServer->listen(QHostAddress::LocalHost, 4242)) {
            qDebug() << "server is not started";
        } else {
            qDebug() << "server is started";
        }
        m_game = std::make_shared<Game>(game_type::DEFAULT);
    }

    void MyTcpServer::send_to_client(const QJsonDocument& str, QTcpSocket *socket) {
        m_data.clear();
        qDebug() << str;
        QDataStream out(&m_data, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_2);
        out << str;
        socket->write(m_data);
    }

    void MyTcpServer::slotNewConnection() {
        auto cur_socket = m_TcpServer->nextPendingConnection();
        m_TcpSockets.push_back(cur_socket);

        connect(cur_socket, &QTcpSocket::readyRead, this, &MyTcpServer::read_response);
        connect(cur_socket, &QTcpSocket::disconnected, this, &MyTcpServer::disconnect_response);
    }

    void MyTcpServer::produce_json(QJsonObject &jsonObject) {
        QString request_type(jsonObject.value("request_type").toString());
        if (request_type == "game_start") {
            m_game = std::make_shared<Game>(game_type::DEFAULT);
        } else if (request_type == "get_filename") {
            int row = jsonObject.value("row").toInt();
            int col = jsonObject.value("col").toInt();
            std::string filename = m_game->get_field().get_element(col, row).get_filename();
        }
    }

    void MyTcpServer::read_response() {
        QTcpSocket* socket = (QTcpSocket*)sender();
        QJsonObject json;
        auto field = m_game->get_field();
        for (int i = 0; i < 13; ++i) {
            for (int j = 0; j < 13; ++j) {
                json.insert((std::to_string(j) + ' ' + std::to_string(i)).c_str(),
                            field.get_element(j, i).get_filename().c_str());
            }
        }
        send_to_client(QJsonDocument(json), socket);
    }

    void MyTcpServer::disconnect_response() {
        QTcpSocket* socket = (QTcpSocket*)sender();
        socket->close();
    }

}