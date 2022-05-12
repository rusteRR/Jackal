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
#include "thread.h"
#include "game.h"

namespace jackal {
    class Server : public QTcpServer
    {
    Q_OBJECT
    public:
        explicit Server(QObject *parent = nullptr);

    protected:
        void incomingConnection(qintptr socketDescription) override;
    private slots:
        void get_field_slot(jackal::Field &field);
        void game_start_slot();
    private:
        std::shared_ptr<Game> m_game{nullptr};
        int m_players_amount{0};
    };

}

#endif //JACKALUI_SERVER_H
