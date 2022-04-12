#include "server.h"

namespace jackal {
    MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent)
    {
        m_TcpServer = new QTcpServer(this);

        connect(m_TcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

        if(!m_TcpServer->listen(QHostAddress::LocalHost, 4242)){
            qDebug() << "server is not started";
        } else {
            qDebug() << "server is started";
        }
    }

    void MyTcpServer::slotNewConnection()
    {
        auto cur_socket = m_TcpServer->nextPendingConnection();
        m_TcpSockets.push_back(cur_socket);

        cur_socket->write("Hello, World!!! I am echo server!\r\n");

        connect(cur_socket, &QTcpSocket::readyRead, this, [cur_socket, this](){
            while(cur_socket->bytesAvailable()>0)
            {
                QJsonObject jsonObject = QJsonDocument::fromJson(cur_socket->readAll()).object();
                produce_json(jsonObject);
            }
        });
        connect(cur_socket, &QTcpSocket::disconnected, this, [cur_socket](){
            cur_socket->close();
        });
    }
    void MyTcpServer::produce_json(QJsonObject &jsonObject) {
        QString request_type(jsonObject.value("request_type").toString());
        if (request_type == "game_start"){
            m_game = std::make_shared<Game>(game_type::DEFAULT);
        } else if (request_type == "get_filename") {
            int row = jsonObject.value("row").toInt();
            int col = jsonObject.value("col").toInt();
            std::string filename = m_game->get_field().get_element(col, row).get_filename();
        }
    }
}