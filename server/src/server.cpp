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
        QThread* thread = new QThread(this);
        ClientWorker* worker = new ClientWorker(socketDescription, m_players_amount++);
        connect(worker, &ClientWorker::finish, thread, &QThread::quit);
        connect(worker, &ClientWorker::send_field, this, &Server::send_field_slot);
        connect(worker, &ClientWorker::game_start, this, &Server::game_start_slot);
        connect(worker, &ClientWorker::process_move, this, &Server::process_move_slot);
        connect(worker, &ClientWorker::update_my_turn, this, &Server::update_my_turn_slot);
        connect(this, &Server::send_json, worker, &ClientWorker::json_response);
        connect(this, &Server::send_my_turn_flag, worker, &ClientWorker::update_turn_response);
        connect(thread, &QThread::finished, worker, &ClientWorker::deleteLater);
        worker->moveToThread(thread);
        thread->start();
    }

    void Server::game_start_slot() {
        qDebug() << "Game start signal from user";
        if (m_players_amount == MAX_PLAYERS_AMOUNT){
            qDebug() << "game created";
            m_game = std::make_shared<Game>(game_type::DEFAULT);
            //emit send_json(m_game->get_current_state());
        }
    }

    void Server::send_field_slot() {
        QJsonObject json;
        auto field = m_game->get_field();
        for (int i = 0; i < 13; ++i) {
            for (int j = 0; j < 13; ++j) {
                json.insert((std::to_string(j) + ' ' + std::to_string(i)).c_str(),
                             field.get_element(j, i).get_filename().c_str());
            }
        }
        emit send_json(json);
    }
    
    void Server::send_error(const QString &str) {
        QJsonObject error;
        error.insert("game", "Jackal");
        error.insert("request_type", "requests_error");
        error.insert("error", str);
        emit send_json(error);
    }
    
    void Server::process_move_slot(const QString &request_type, int pirate_id, int col_to, int row_to) {
        QJsonObject result = m_game->process_move(request_type.toStdString(), pirate_id, col_to, row_to);
        emit send_json(result);
    }
    
    void Server::update_my_turn_slot(int id) {
        emit send_my_turn_flag(m_players_amount == MAX_PLAYERS_AMOUNT && m_game->current_player_id() == id);
    }
}
