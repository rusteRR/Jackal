#ifndef JACKALUI_THREAD_H
#define JACKALUI_THREAD_H

#include <Qthread>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDataStream>
#include "game.h"

namespace jackal {
    class ClientThread : public QThread {

    Q_OBJECT

    public:
        ClientThread(int socketDescription, QObject *parent);

        void run() override;

    signals:

        void error(QTcpSocket::SocketError socketError);

        void get_field(jackal::Field &field);

        void game_start();

    private slots:

        void read_response();

        void disconnect_response();

    private:
        QByteArray m_data;

        QTcpSocket* m_socket;

        void produce_json(QJsonObject &jsonObject);

        void send_to_client(const QJsonDocument &str, QTcpSocket *socket);
    };
}

#endif //JACKALUI_THREAD_H
