#include "player.h"

jackal::Player::Player(int total_pirates, int col, int row) : m_total_coins(0), m_rum_bottles(0), m_ship(col, row) {
    for (int i = 0; i < total_pirates; i++) {
        m_pirates.push_back(std::make_shared<Pirate>(col, row, &m_ship, this));
    }
}

std::shared_ptr<jackal::Pirate> jackal::Player::get_pirate(int pirate_id) {
    if (pirate_id >= m_pirates.size()) return nullptr;
    return m_pirates[pirate_id];
}

std::vector<std::shared_ptr<jackal::Pirate>> jackal::Player::get_all_pirates() const {
    return m_pirates;
}

void jackal::Player::set_rum_bottles(int n) {
    m_rum_bottles += n;
}

bool jackal::Player::move_ship(Coords coords) {
    return m_ship.move(coords);
}

void jackal::Player::increase_coins(int n) {
    m_total_coins += n;
}

int jackal::Player::get_coins_earned() const {
    return m_total_coins;
}

jackal::Coords jackal::Player::get_ship_coords() const {
    return m_ship.get_coords();
}

void jackal::Player::decrease_debuff() {
    for (auto &pirate : m_pirates) {
        pirate->decrease_debuff();
    }
}

void jackal::Player::ressurect_pirates(Coords spawn_coords) {
    for (auto &pirate : m_pirates) {
        if (pirate->get_status() == status::DEAD) {
            pirate->move(spawn_coords);
            pirate->stuck(HEAL_TIME + 1);
        }
    }
}

int jackal::Player::get_rum_bottles() const {
    return m_rum_bottles;
}
