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

    void pass_coords(int col, int row);

signals:
    void field_response(const QJsonDocument& str);

    void open_cell(int row, int col);

private:
    QTcpSocket* m_socket;
    QDataStream in;

private slots:
    void read_response();
};


#endif
