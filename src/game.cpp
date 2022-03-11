#include "game.h"
#include <stdexcept>
#include <iostream>

struct invalid_turn : std::runtime_error {
    invalid_turn() : std::runtime_error("Incorrect move"){
    }
};

namespace jackal {

    void Game::process_move(int col_from, int row_from, int col_to, int row_to) {

        // TODO : for unusual events(plane, balloon, etc...) checking move correctness
        // TODO : has difference. Have to process this cases soon.

        check_move_correctness(col_from, row_from, col_to, row_to);
        Event &current_event = m_field.get_element(col_to, row_to);

        // TODO : next line don't process the case when pirates of different types
        // TODO : stay in the same cell.

        std::shared_ptr<Pirate> pirate_to_go = m_players[m_current_player].get_pirate(col_from, row_from);
        if (pirate_to_go) {
            pirate_to_go->move(col_to - col_from, row_to - row_from);
            pirate_to_go->attack_pirate(*this);
            current_event.invoke(*pirate_to_go);
            EventType event_type = current_event.invoke(*pirate_to_go);
            while (event_type != EventType::SIMPLE) {
                current_event = m_field.get_element(col_to, row_to);
                pirate_to_go->attack_pirate(*this);
                event_type = current_event.invoke(*pirate_to_go);
            }

            change_turn();
        }
        else {
            std::cout << "Incorrect move!" << std::endl;
        }
    }

    void Game::check_move_correctness(int col_from, int row_from, int col_to, int row_to) {
        // TODO : some cases were not processed.
        if (abs(col_from - col_to) > 1 || abs(row_from - row_to) > 1) {
            throw invalid_turn();
        }
    }

    Game::Game(game_type type_) {
        m_field.generate_field();
        // TODO : maybe this part will be changed. It's hard to make a correct implementation
        // TODO : because field generates without borders.
        m_players.emplace_back(total_pirates, m_total_cols / 2, 0);
        m_players.emplace_back(total_pirates, m_total_cols - 1, m_total_rows / 2);
        m_players.emplace_back(total_pirates, m_total_cols / 2, m_total_rows - 1);
        m_players.emplace_back(total_pirates, 0, m_total_rows / 2);
    }

    void Game::change_turn() noexcept {
        m_current_player = (m_current_player + 1) % 4;
    }

    std::vector<std::shared_ptr<Pirate>> Game::get_pirates() const {
        std::vector<std::shared_ptr<Pirate>> result;
        for (int i = 0; i < 4; i++) {
            if (i == m_current_player) {
                continue;
            }
            std::vector<std::shared_ptr<Pirate>> cur_pirate = m_players[i].get_all_pirates();
            result.insert(result.end(), cur_pirate.begin(), cur_pirate.end());
        }
        return result;
    }
}

