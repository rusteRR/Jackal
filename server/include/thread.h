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
        explicit ClientWorker(int socketDescription, QObject *parent = nullptr);

        //void run();

    signals:

        void error(QTcpSocket::SocketError socketError);

        void send_field();

        void game_start();
        
        void process_move(const QString& request_type, int pirate_id, int col_to, int row_to);
        
        void finish();

    public slots:
        
        void json_response(QJsonObject json);
    
    private slots:
    
        void read_response();

        void disconnect_response();

    private:
        QTcpSocket* m_socket{nullptr};
        
        int m_socket_description;
        
        QDataStream in;
        
        bool ship_clicked{false};
        
        int pirate_clicked_id{-1};
        
        void produce_json(QJsonDocument &json);

        void send_to_client(const QJsonDocument &str);
        
        void send_to_client(const QJsonObject &obj);
        
        void send_error(const QString &str);
    };
}

#endif //JACKALUI_THREAD_H
