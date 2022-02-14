#ifndef GAME_H_
#define GAME_H_

#include <vector>
#include "field.h"
#include "player.h"

namespace jackal {
    enum class game_type{};
    class Game {
    public:
        void change_turn() noexcept;
        
        
    private:
        field m_field;
        std::vector<Player*> m_players;
        int m_current_player;
};

} // namespace jackal

#endif //GAME_H_
