#include "server.h"

namespace jackal {
    Server::Server(QObject *parent) : QTcpServer(parent) {
        if (!this->listen(QHostAddress::Any, 4242)) {
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
        connect(worker, &ClientWorker::process_move, this, &Server::process_move_slot, Qt::BlockingQueuedConnection);
        connect(worker, &ClientWorker::register_player, this, &Server::register_player_slot, Qt::BlockingQueuedConnection);
        connect(worker, &ClientWorker::quit, this, &Server::quit_slot, Qt::BlockingQueuedConnection);
        connect(worker, &ClientWorker::get_possible_turns, this, &Server::get_possible_turns_slot, Qt::BlockingQueuedConnection);
        connect(this, &Server::confirm_registration, worker, &ClientWorker::confirm_registration_slot);
        connect(this, &Server::send_json, worker, &ClientWorker::send_json_slot);
        connect(this, &Server::update_status, worker, &ClientWorker::update_status_slot);
        connect(thread, &QThread::finished, worker, &ClientWorker::deleteLater);
        worker->moveToThread(thread);
        thread->start();
    }
    
    void Server::process_move_slot(const QString &request_type, int pirate_id, int col_to, int row_to) {
        qDebug() << "process_move_slot";
        QJsonObject result = m_game->process_move(request_type.toStdString(), pirate_id, col_to, row_to);
        qDebug() << "process_move successful";
        int cur_id = m_game->current_player_id();
        emit update_status(cur_id);
        emit send_json(result, cur_id);
    }

    void Server::register_player_slot(QString name, int thread_id) {
        int player_id = -1;
        if (m_name_id.find(name) != m_name_id.end()) {
            qDebug() << "Already registered: " << name << ". Id is " << m_name_id[name];
            player_id = m_name_id[name];
            if (!m_playing[player_id]){
                m_playing[player_id] = true;
            } else{
                player_id = -1;
            }
        } else if (m_players_amount < MAX_PLAYERS_AMOUNT){
            player_id = m_players_amount++;
            m_name_id[name] = player_id;
            m_playing[player_id] = true;
            if (m_players_amount == MAX_PLAYERS_AMOUNT && m_game == nullptr) {
                qDebug() << "game created";
                m_game = std::make_shared<Game>(game_type::DEFAULT);
            }
        }
        emit confirm_registration(player_id, thread_id);
        send_players_names();
        if (m_game != nullptr && player_id != -1){
            QJsonObject state = m_game->get_current_state();
            int cur_id = m_game->current_player_id();
            emit update_status(cur_id);
            emit send_json(state, cur_id);
        }
    }
    
    void Server::send_players_names() {
        QJsonObject json;
        QJsonArray players;
        int cnt = 0;
        std::vector<std::pair<int, QString>> v;
        for (auto &x : m_name_id){
            v.emplace_back(x.second, x.first);
            cnt++;
        }
        std::sort(v.begin(),v.end());
            while(cnt < MAX_PLAYERS_AMOUNT){
            v.emplace_back(cnt++, "Waiting...");
        }
        for (auto &x : v){
            QJsonObject player;
            player["name"] = x.second;
            player["id"] = x.first;
            players.append(player);
        }
        json.insert("game", "Jackal");
        json.insert("response_type", "players");
        json.insert("players", players);
        emit send_json(json, -1);
    }
    
    void Server::get_possible_turns_slot(int pirate_id, int sender_id) {
        QJsonObject json = Handler::get_possible_moves(*m_game, pirate_id);
        send_json(json, sender_id);
    }
    
    void Server::quit_slot(int id) {
        m_playing[id] = false;
    }
}
