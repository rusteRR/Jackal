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
    class Server : public QTcpServer {
    Q_OBJECT
    public:
        explicit Server(QObject *parent = nullptr);

    protected:
        void incomingConnection(qintptr socketDescription) override;

    private slots:

        void get_field_slot(jackal::Field &field);

        void game_start_slot();

        void process_move_slot(const std::string &request_type, int pirate_id, int col_to, int row_to, QJsonObject& result);

    private:
        std::shared_ptr<Game> m_game{nullptr};
        int m_players_amount{0};
    };

}

#endif //JACKALUI_SERVER_H
