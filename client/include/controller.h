#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <QObject>
#include <QString>
#include <QTcpSocket>
#include <QDataStream>

class Controller : public QObject {
Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);

    void wait_filename();

public slots:

    void start_game();

    void end_game();

    void pass_coords(int row, int col);

    void ship_click(int id);

signals:

    void field_response(const QJsonDocument &str);

    void open_cell(int row, int col);

    void move_ship(int row_from, int col_from, int row_to, int col_to, int id, int money);

private:
    void send_to_server(const QJsonDocument& str);
    void send_to_server(const QJsonObject& obj);
    QTcpSocket *m_socket;
    QDataStream in;
private slots:

    void read_response();
};


#endif
