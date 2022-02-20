#ifndef GAME_H_
#define GAME_H_

#include "field.h"
#include "player.h"
#include <vector>

namespace jackal {
    enum class game_type {DEFAULT};

    class Game {
    public:
        Game(game_type type_);

        void change_turn() noexcept;
        
    private:
        Field m_field;
        std::vector<Player> m_players;
        game_type m_game_type;
        int m_current_player;
};

} // namespace jackal

#endif //GAME_H_
