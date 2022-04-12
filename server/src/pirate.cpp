#include "pirate.h"
#include "game.h"
#include <vector>
#include <iostream>
#include <memory>

namespace jackal {

    Pirate::Pirate(int col, int row, Ship *ship) : m_col(col), m_row(row), m_status(status::ALIVE), m_ship(ship) {
    }

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
            if (pirate_ptr->get_coords() == coords && pirate_ptr->get_status() == status::PROTECTED) {
                this->go_to_ship();
                return;
            }
            if (pirate_ptr->get_coords() == coords) {
                pirate_ptr->go_to_ship();
            }
        }
    }

    void Pirate::go_to_ship() {
        std::pair<int, int> ship_coords = m_ship->get_coords();
        m_col = ship_coords.first;
        m_row = ship_coords.second;
    }

    void Pirate::stuck(int steps) {
        std::cout << "STUCKED FOR " << steps << " STEPS" << std::endl;
        m_stucked_for = steps;
        m_status = status::STUCK;
    }

    void Pirate::die() {
        std::cout << "DEAD" << std::endl;
        m_status = status::DEAD;
        //emit PirateIsDead();
    }

    void Pirate::set_last_move(eventType type, int col, int row) {
        m_last_move = std::make_pair(type, std::make_pair(col, row));
    }

    void Pirate::ice() {
        if (m_last_move.first == eventType::HORSE) {
            // TODO
        }
        else if (m_last_move.first == eventType::PLANE) {
            // TODO
        }
        else if (m_last_move.first == eventType::MULTIPOINTER) {
            // TODO
        }
        else {
            std::pair<int, int> diff_coords = m_last_move.second;
            move(diff_coords.first, diff_coords.second);
        }
    }

    status Pirate::get_status() const {
        return m_status;
    }

    void Pirate::set_status(status cur_status) {
        m_status = cur_status;
    }
}