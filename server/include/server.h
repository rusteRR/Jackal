#ifndef JACKALUI_SERVER_H
#define JACKALUI_SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#include <memory>
#include <QVector>
#include <QJsonObject>
#include <QJsonDocument>
#include <QString>
#include "game.h"

namespace jackal {
    class MyTcpServer : public QObject
    {
        Q_OBJECT
    public:
        explicit MyTcpServer(QObject *parent = nullptr);

    private slots:
        void slotNewConnection();
        void read_response();
        void disconnect_response();
    private:
        QTcpServer * m_TcpServer;
        QVector<QTcpSocket*> m_TcpSockets{};
        std::shared_ptr<Game> m_game{nullptr};
        QByteArray m_data;
        void produce_json(QJsonObject &jsonObject);
        void send_to_client(const QJsonDocument& str, QTcpSocket* socket);
    };
    
}

#endif //JACKALUI_SERVER_H
