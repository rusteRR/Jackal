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
        Event &current_event = m_field.get_element();

        // TODO : next line don't process the case when pirates of different types
        // TODO : stay in the same cell.

        Pirate &pirate_to_go = m_players[m_current_player]->get_pirate(col_from, row_from);
        current_event.invoke(pirate_to_go);
    }

    void Game::check_move_correctness(int col_from, int row_from, int col_to, int row_to) {
        // TODO : some cases were not processed.
        if (abs(col_from - col_to) >= 1 || abs(row_from - row_to) >= 1) {
            throw invalid_turn();
        }
    }
}

