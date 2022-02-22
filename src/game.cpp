#include "game.h"
#include <stdexcept>

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

        Pirate* pirate_to_go = m_players[m_current_player].get_pirate(col_from, row_from);
        if (pirate_to_go) {
            pirate_to_go->move(col_to - col_from, row_to - row_from);
            current_event.invoke(*pirate_to_go);

            // TODO : 1. some events require an answer from player - is not processed.
            // TODO : 2. some events(ex: pointer) move pirate, then have to invoke one
            // TODO : more event. Now this case is not processed. (Solution(?): each event
            // TODO : contains a status and returns it.)

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
}

