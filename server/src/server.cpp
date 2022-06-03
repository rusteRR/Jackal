#include "server.h"

namespace jackal {
    Server::Server(QObject *parent) : QTcpServer(parent) {
        if (!this->listen(QHostAddress::Any, 4242)) {
            qDebug() << "server is not started";
            return;
        } else {
            qDebug() << "server is started";
//            qDebug() << "listening at" << ;
        }
    }

    void Server::incomingConnection(qintptr socketDescription) {
        QThread *thread = new QThread(this);
        ClientWorker *worker = new ClientWorker(socketDescription,  m_threads_ids++);
        connect(worker, &ClientWorker::finish, thread, &QThread::quit);
        connect(worker, &ClientWorker::game_start, this, &Server::game_start_slot, Qt::BlockingQueuedConnection);
        connect(worker, &ClientWorker::process_move, this, &Server::process_move_slot, Qt::BlockingQueuedConnection);
        connect(worker, &ClientWorker::register_player, this, &Server::register_player_slot, Qt::BlockingQueuedConnection);
        connect(worker, &ClientWorker::quit, this, &Server::quit_slot);
        connect(this, &Server::confirm_registration, worker, &ClientWorker::confirm_registration_slot);
        connect(this, &Server::send_json, worker, &ClientWorker::send_json_slot);
        connect(this, &Server::update_status, worker, &ClientWorker::update_status_slot);
        connect(thread, &QThread::finished, worker, &ClientWorker::deleteLater);
        worker->moveToThread(thread);
        thread->start();
    }

    void Server::game_start_slot() {
        QMutexLocker lock(&m_mutex);
        qDebug() << "Game start signal from user";
        if (m_players_amount == MAX_PLAYERS_AMOUNT && m_game == nullptr) {
            qDebug() << "game created";
            m_game = std::make_shared<Game>(game_type::DEFAULT);
            int cur_id = m_game->current_player_id();
            emit update_status(cur_id);
            //emit send_json(m_game->get_current_state());  
        }
    }

    void Server::process_move_slot(const QString &request_type, int pirate_id, int col_to, int row_to) {
        QMutexLocker lock(&m_mutex);
        qDebug() << "process_move_slot";
        QJsonObject result = m_game->process_move(request_type.toStdString(), pirate_id, col_to, row_to);
        qDebug() << "process_move successful";
        int cur_id = m_game->current_player_id();
        emit update_status(cur_id);
        emit send_json(result);
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
        }
        emit confirm_registration(player_id, thread_id);
    }
    
    void Server::quit_slot(int id) {
        m_playing[id] = false;
    }
}
