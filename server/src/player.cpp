#include "player.h"
#include <optional>


jackal::Player::Player(int total_pirates, int col, int row) : m_total_coins(0), m_rum_bottles(0) {
    m_ship = std::make_shared<Ship>(col, row).get();
    for (int i = 0; i < total_pirates; i++) {
        m_pirates.push_back(std::make_shared<Pirate>(col, row, m_ship, this));
    }
}

std::shared_ptr<jackal::Pirate> jackal::Player::get_pirate(int col, int row) {
    for (auto& pirate : m_pirates) {
        if (pirate->get_coords() == std::pair(col, row)) {
            return pirate;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<jackal::Pirate>> jackal::Player::get_all_pirates() const {
    return m_pirates;
}

void jackal::Player::get_rum_bottles(int n) {
    m_rum_bottles += n;
}
