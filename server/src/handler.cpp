#include "handler.h"
#include <QJsonDocument>
#include <iostream>

QJsonObject jackal::Handler::make_json(int pirate_id, const std::string& type, bool status, int x, int y) {
    QString response_status;
    if (status) {
        response_status = "completed";
    }
    else {
        response_status = "incorrect";
    }
    QJsonObject qObj;
    qObj.insert("game", "Jackal");
    qObj.insert("response_type", QString::fromStdString(type));
    qObj.insert("response_status", response_status);
    qObj.insert("pirate_id", pirate_id);
    if (x != -1 && y != -1) {
        qObj.insert("column", x);
        qObj.insert("row", y);
    }
    return qObj;
}
