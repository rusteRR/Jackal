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

        //void run();

    signals:

        void error(QTcpSocket::SocketError socketError);

        void send_field();

        void game_start();
        
        void process_move(const QString& request_type, int pirate_id, int col_to, int row_to);
        
        void register_player(QString name, int thread_id);
        
        void finish();

        void make_turn(int id);

    public slots:
        
        void json_response(QJsonObject json);
        
        void make_turn_response(int id);
        
        void confirm_registration_slot(int player_id, int sender_id);
    
    private slots:
    
        void read_response();

        void disconnect_response();

    private:
        QTcpSocket* m_socket{nullptr};
        
        int m_socket_description;
        
        QDataStream m_in;
        
        QJsonDocument m_json;
        
        bool m_ship_clicked{false};
        
        bool m_pirate_clicked{false};
        
        int m_player_id{-1};
        
        int m_thread_id;
        
        void produce_json(QJsonDocument &json);

        void send_to_client(const QJsonDocument &str);
        
        void send_to_client(const QJsonObject &obj);
        
        void send_error(const QString &str);
    };
}

#endif //JACKALUI_THREAD_H
