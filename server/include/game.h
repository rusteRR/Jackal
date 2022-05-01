#ifndef GAME_H_
#define GAME_H_

#include "field.h"
#include "player.h"
#include "settings.h"
#include <vector>

namespace jackal {

    enum class game_type {DEFAULT};

    class Game {
    public:
        explicit Game(game_type type);
        void process_move(const std::string& request_type, int pirate_id, int col_to = -1, int row_to = -1);
        [[nodiscard]] std::vector<std::shared_ptr<Pirate>> get_pirates() const;
        [[nodiscard]] const Field& get_field() const;
        
    private:
        Settings m_settings{};
        Field m_field{};
        std::vector<Player> m_players;
        game_type m_game_type;
        int coins_remaining;
        int m_current_player;
        int m_total_cols = COORD_UPPER_BOUND + 1;
        int m_total_rows = COORD_UPPER_BOUND + 1;
        int total_pirates = 3;

        void change_turn() noexcept;
        bool check_move_correctness(const std::shared_ptr<Pirate>& pirate_to_go, Coords new_coords);
        void take_coin(int pirate_id);
        bool check_win() const;
};

} // namespace jackal

#endif //GAME_H_
