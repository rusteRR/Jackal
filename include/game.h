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

        void process_move(int col_pirate, int row_pirate, int col_to, int row_to);

        void change_turn() noexcept;
        
    private:
        Field m_field;
        std::vector<std::shared_ptr<Player>> m_players;
        game_type m_game_type;
        int m_current_player;

        void check_move_correctness(int col_from, int row_from, int col_to, int row_to);
};

} // namespace jackal

#endif //GAME_H_
