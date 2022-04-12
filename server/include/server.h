#ifndef JACKALUI_SERVER_H
#define JACKALUI_SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <memory>
#include <QVector>
#include "game.h"

namespace jackal {
    class MyTcpServer : public QObject
    {
        Q_OBJECT
    public:
        explicit MyTcpServer(QObject *parent = nullptr);

    public slots:
        void slotNewConnection();

    private:
        QTcpServer * m_TcpServer;
        QVector<QTcpSocket*> m_TcpSockets{};
        std::shared_ptr<Game> m_game{nullptr};
    };
    
}

#endif //JACKALUI_SERVER_H
