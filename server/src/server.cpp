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
        QThread *thread = new QThread(this);
        ClientWorker *worker = new ClientWorker(socketDescription,  m_threads_ids++);
        connect(worker, &ClientWorker::finish, thread, &QThread::quit);
        connect(worker, &ClientWorker::send_field, this, &Server::send_field_slot);
        connect(worker, &ClientWorker::game_start, this, &Server::game_start_slot);
        connect(worker, &ClientWorker::process_move, this, &Server::process_move_slot);
        connect(worker, &ClientWorker::make_turn, this, &Server::make_turn_slot);
        connect(worker, &ClientWorker::register_player, this, &Server::register_player_slot);
        connect(this, &Server::confirm_registration, worker, &ClientWorker::confirm_registration_slot);
        connect(this, &Server::send_json, worker, &ClientWorker::json_response);
        connect(this, &Server::make_turn, worker, &ClientWorker::make_turn_response);
        connect(thread, &QThread::finished, worker, &ClientWorker::deleteLater);
        worker->moveToThread(thread);
        thread->start();
    }

    void Server::game_start_slot() {
        qDebug() << "Game start signal from user";
        if (m_players_amount == MAX_PLAYERS_AMOUNT && m_game == nullptr) {
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

    void Server::make_turn_slot(int id) {
        qDebug() << m_players_amount;
        if (m_players_amount == MAX_PLAYERS_AMOUNT) {
            qDebug() << m_game->current_player_id() << id;
        }
        if (m_players_amount == MAX_PLAYERS_AMOUNT && m_game->current_player_id() == id){
            emit make_turn(id);
        }
    }

    void Server::register_player_slot(QString name, int thread_id) {
        int player_id = -1;
        if (m_name_id.find(name) != m_name_id.end()) {
            qDebug() << "Already registered: " << name << ". Id is " << m_name_id[name];
            player_id = m_name_id[name];
        } else if (m_players_amount < MAX_PLAYERS_AMOUNT){
            player_id = m_players_amount++;
            m_name_id[name] = player_id;
        }
        emit confirm_registration(player_id, thread_id);
    }
}
