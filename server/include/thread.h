#ifndef JACKALUI_THREAD_H
#define JACKALUI_THREAD_H

#include <Qthread>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDataStream>
#include <QString>
#include "game.h"

namespace jackal {
    class ClientWorker : public QObject {

    Q_OBJECT

    public:
        explicit ClientWorker(int socketDescription, int thread_id, QObject *parent = nullptr);

    signals:

        void error(QTcpSocket::SocketError socketError);

        void game_start();
        
        void process_move(const QString& request_type, int pirate_id, int col_to, int row_to);
        
        void register_player(QString name, int thread_id);
        
        void quit(int id);
        
        void finish();

    public slots:
        
        void send_json_slot(QJsonObject json);
        
        void update_status_slot(int id);
        
        void confirm_registration_slot(int player_id, int sender_id);
    
    private slots:
    
        void read_response();

        void disconnect_response();

    private:
        QTcpSocket* m_socket{nullptr};
        
        int m_socket_description;
        
        QDataStream m_in;
        
        bool m_ship_clicked{false};
        
        bool m_pirate_clicked{false};
        
        bool is_my_turn{false};
        
        int m_player_id{-1};
        
        int m_thread_id;
        
        void produce_json(QJsonDocument &json);

        void send_to_client(const QJsonDocument &str);
        
        void send_to_client(const QJsonObject &obj);
        
        void send_error(const QString &str);
    };
}

#endif //JACKALUI_THREAD_H
