#ifndef GAME_H_
#define GAME_H_

#include "field.h"
#include "player.h"
#include "settings.h"
#include <vector>

namespace jackal {
    const int COORD_LOWER_BOUND = 0;
    const int COORD_UPPER_BOUND = 12;

    enum class game_type {DEFAULT};

    class Game {
    public:
        explicit Game(game_type type);
        void process_move(const std::string& request_type, int pirate_id, int col_to = -1, int row_to = -1);
        [[nodiscard]] std::vector<std::shared_ptr<Pirate>> get_pirates() const;
        void change_turn() noexcept;
        [[nodiscard]] const Field& get_field() const {
            return m_field;
        }
        
    private:
        Settings m_settings{};
        Field m_field{};
        std::vector<Player> m_players;
        game_type m_game_type;
        int m_current_player;
        int m_total_cols = COORD_UPPER_BOUND + 1;
        int m_total_rows = COORD_UPPER_BOUND + 1;
        int total_pirates = 3;

        bool check_move_correctness(const std::shared_ptr<Pirate>& pirate_to_go, int col_to, int row_to);

        void take_coin(int pirate_id);
};

} // namespace jackal

#endif //GAME_H_
