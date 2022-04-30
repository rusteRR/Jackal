#include "player.h"

jackal::Player::Player(int total_pirates, int col, int row) : m_total_coins(0), m_rum_bottles(0), m_ship(col, row) {
    for (int i = 0; i < total_pirates; i++) {
        m_pirates.push_back(std::make_shared<Pirate>(col, row, &m_ship, this));
    }
    for (const auto& pirate : m_pirates) {
        m_ship.add_pirate(pirate);
    }
}

std::shared_ptr<jackal::Pirate> jackal::Player::get_pirate(int pirate_id) {
    if (pirate_id >= m_pirates.size()) return nullptr;
    return m_pirates[pirate_id];
}

std::vector<std::shared_ptr<jackal::Pirate>> jackal::Player::get_all_pirates() const {
    return m_pirates;
}

void jackal::Player::get_rum_bottles(int n) {
    m_rum_bottles += n;
}

void jackal::Player::move_ship(int col, int row) {
    m_ship.move(col, row);
}

void jackal::Player::increase_coins(int n) {
    m_total_coins += n;
}
