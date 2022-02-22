#include "player.h"
#include <optional>

namespace jackal {

     Pirate* Player::get_pirate(int col, int row) {
        for (auto& pirate : m_pirates) {
            if (pirate.get_coords() == std::pair(col, row)) {
                return &pirate;
            }
        }
        return nullptr;
    }
}