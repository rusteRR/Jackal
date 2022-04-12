#include "server.h"

namespace jackal {
    MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent)
    {
        m_TcpServer = new QTcpServer(this);

        connect(m_TcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

        if(!m_TcpServer->listen(QHostAddress::LocalHost, 6000)){
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

        connect(cur_socket, &QTcpSocket::readyRead, this, [cur_socket](){
            while(cur_socket->bytesAvailable()>0)
            {
                QByteArray array = cur_socket->readAll();
                cur_socket->write(array);
            }
        });
        connect(cur_socket, &QTcpSocket::disconnected, this, [cur_socket](){
            cur_socket->close();
        });
    }
}