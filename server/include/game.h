#ifndef GAME_H_
#define GAME_H_

#include "field.h"
#include "player.h"
#include "settings.h"
#include <vector>
#include <QJsonObject>

namespace jackal {

    class Handler;

    enum class game_type {DEFAULT};

    class Game {
        friend class Handler;
    public:
        explicit Game(game_type type);
        QJsonObject process_move(const std::string& request_type, int pirate_id, int col_to = -1, int row_to = -1);
        [[nodiscard]] std::vector<std::shared_ptr<Pirate>> get_pirates() const;
        [[nodiscard]] int current_player_id() const;
        [[nodiscard]] const Field& get_field() const;
        [[nodiscard]] QJsonObject get_current_state();
        
    private:
        Settings m_settings{};
        Field m_field{};
        std::vector<std::shared_ptr<Player>> m_players;
        game_type m_game_type;
        int coins_remaining;
        int m_current_player;
        int m_total_cols = COORD_UPPER_BOUND + 1;
        int m_total_rows = COORD_UPPER_BOUND + 1;
        int total_pirates = 3;

        void change_turn() noexcept;
        bool check_move_correctness(const std::shared_ptr<Pirate>& pirate_to_go, Coords new_coords);
        [[nodiscard]] static bool check_is_water_cell(Coords coords) ;
        [[nodiscard]] bool check_if_pirates_on_cell(Coords coords);
        bool take_coin(int pirate_id, int coins_to_take);
        void drop_coin(int pirate_id);
        [[nodiscard]] bool check_win() const;
};

} // namespace jackal

#endif //GAME_H_
