#ifndef HANDLER_H_
#define HANDLER_H_

#include "game.h"
#include <QJsonObject>

namespace jackal {
    class Handler {
    public:
        static QJsonObject make_json(int pirate_id, const std::string& type, bool status, int x = -1, int y = -1);
        static QJsonObject get_current_game_state(Game& game);
        static QJsonObject get_error_json(const std::string& error_text);
    };
}

#endif