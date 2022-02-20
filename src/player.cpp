#include "player.h"

namespace jackal {

    Pirate &Player::get_pirate(int col, int row) {
        for (const auto& pirate_ptr : m_pirates) {
            if (pirate_ptr->get_col() == col && pirate_ptr->get_row() == row) {
                return *pirate_ptr;
            }
        }
    }
}