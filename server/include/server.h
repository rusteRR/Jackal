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
#include <map>
#include <QMutex>
#include <QMutexLocker>
#include "thread.h"
#include "game.h"

namespace jackal {
    class Server : public QTcpServer {
    Q_OBJECT
    public:
        explicit Server(QObject *parent = nullptr);

    protected:
        void incomingConnection(qintptr socketDescription) override;

    signals:

        void send_json(QJsonObject json);

        void update_status(int id);
        
        void confirm_registration(int id, int sender_id);

    private slots:

        void register_player_slot(QString name, int id);

        void game_start_slot();

        void process_move_slot(const QString &request_type, int pirate_id, int col_to, int row_to);
        
        void quit_slot(int id);
        
    private:    
        std::shared_ptr<Game> m_game{nullptr};
        int m_players_amount{0};
        int m_threads_ids{0};
        const int MAX_PLAYERS_AMOUNT{4};
        std::map<QString, int> m_name_id;
        std::map<int, bool> m_playing;
        QMutex m_mutex;
    };

}

#endif //JACKALUI_SERVER_H
