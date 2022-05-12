#include "server.h"

namespace jackal {
    Server::Server(QObject *parent) : QTcpServer(parent) {
        if (!this->listen(QHostAddress::LocalHost, 4242)) {
            qDebug() << "server is not started";
            return;
        } else {
            qDebug() << "server is started";
        }
    }

    void Server::incomingConnection(qintptr socketDescription) {
        ClientThread *thread = new ClientThread(socketDescription, this);
        connect(thread, &ClientThread::finished, thread, &ClientThread::deleteLater);
        connect(thread, &ClientThread::get_field, this, &Server::get_field_slot);
        connect(thread, &ClientThread::game_start, this, &Server::game_start_slot);
        thread->start();
    }

    void Server::game_start_slot() {
        qDebug() << "Game start signal from user";
        m_players_amount++;
        if (m_players_amount == 1){
            m_game = std::make_shared<Game>(game_type::DEFAULT);
        }
    }

    void Server::get_field_slot(Field &field) {
        field = m_game->get_field();
    }

    void Server::process_move_slot(const std::string &request_type, int pirate_id, int col_to, int row_to, QJsonObject& result) {
        result = m_game->process_move(request_type, pirate_id, col_to, row_to, result);
    }
}