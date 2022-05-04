#ifndef HANDLER_H_
#define HANDLER_H_

#include <QJsonObject>

namespace jackal {
    class Handler {
    public:
        static QJsonObject make_json(int pirate_id, const std::string& type, bool status, int x = -1, int y = -1);
    };
}

#endif