#include "player.h"
#include <optional>

namespace jackal {

     std::shared_ptr<Pirate> Player::get_pirate(int col, int row) {
        for (auto& pirate : m_pirates) {
            if (pirate->get_coords() == std::pair(col, row)) {
                return pirate;
            }
        }
        return nullptr;
    }

    std::vector<std::shared_ptr<Pirate>> Player::get_all_pirates() const {
        return m_pirates;
    }
}