#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <QObject>
#include <QTcpSocket>

class Controller : public QObject {
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);

public slots:
    void start_game();

    void end_game();

private:
    QTcpSocket m_socket;

private slots:
    void on_ready_read();
};


#endif