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
        ClientWorker* worker = new ClientWorker(socketDescription);
        connect(worker, &ClientWorker::finish, thread, &QThread::quit);
        connect(worker, &ClientWorker::send_field, this, &Server::send_field_slot);
        connect(worker, &ClientWorker::game_start, this, &Server::game_start_slot);
        connect(worker, &ClientWorker::process_move, this, &Server::process_move_slot);
        connect(this, &Server::send_json, worker, &ClientWorker::json_response);
        connect(thread, &QThread::finished, worker, &ClientWorker::deleteLater);
        worker->moveToThread(thread);
        thread->start();
    }

    void Server::game_start_slot() {
        qDebug() << "Game start signal from user";
        m_players_amount++;
        if (m_players_amount == 1){
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

    void Server::process_move_slot(const QString &request_type, int pirate_id, int col_to, int row_to) {
        QJsonObject result = m_game->process_move(request_type.toStdString(), pirate_id, col_to, row_to);
        emit send_json(result);
    }
}
