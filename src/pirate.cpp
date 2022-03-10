#include "pirate.h"
#include "game.h"
#include <vector>
#include <memory>

namespace jackal {
    void Pirate::move(int d_col, int d_row) {
        m_col += d_col;
        m_row += d_row;
    }

    std::pair<int, int> Pirate::get_coords() const {
        return {m_col, m_row};
    }

    void Pirate::attack_pirate(Game &game) {
        std::vector<std::shared_ptr<Pirate>> pirates_to_attack = game.get_pirates();
        std::pair<int, int> coords = {m_col, m_row};
        for (const auto& pirate_ptr : pirates_to_attack) {
            if (pirate_ptr->get_coords() == coords) {
                pirate_ptr->set_status(status::DEAD);
            }
        }
    }

    void Pirate::set_status(status new_status) {
        m_status = new_status;
        if (m_status == status::DEAD) {
            std::cout << "DEAD" << std::endl;
            go_to_ship();
        }
    }

    void Pirate::go_to_ship() {
        // TODO : need sheep coord
    }
}