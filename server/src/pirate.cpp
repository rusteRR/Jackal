#include "pirate.h"
#include "game.h"
#include <vector>
#include <iostream>
#include <memory>



jackal::Pirate::Pirate(int col, int row, Ship *ship, Player* owner) :
                    m_coords({col, row}), m_coins(0),
                    m_status(status::ON_BOARD), m_ship(ship), m_owner(owner) {
    m_ship->add_pirate(this);
}


// Make move from cuurent position to position (col, row)
void jackal::Pirate::move(Coords coords) {
    if (m_status == status::ON_BOARD) {
        m_ship->leave_ship(this);
        m_status = status::ALIVE;
    }
    if (coords.x > COORD_UPPER_BOUND) coords.x = COORD_UPPER_BOUND;
    else if (coords.x < COORD_LOWER_BOUND) coords.x = COORD_LOWER_BOUND;
    if (coords.y > COORD_UPPER_BOUND) coords.y = COORD_UPPER_BOUND;
    else if (coords.y < COORD_LOWER_BOUND) coords.y = COORD_LOWER_BOUND;
    m_coords = coords;
    if (get_coords() == m_ship->get_coords()) {
        m_owner->increase_coins(m_coins);
        m_status = status::ON_BOARD;
        m_coins = 0;
    }
}

jackal::Coords jackal::Pirate::get_coords() const {
    return m_coords;
}

void jackal::Pirate::attack_pirate(Game &game) {
    std::vector<std::shared_ptr<Pirate>> pirates_to_attack = game.get_pirates();
    for (const auto& pirate_ptr : pirates_to_attack) {
        if (pirate_ptr->get_coords() == m_coords && pirate_ptr->get_status() == status::PROTECTED) {
            this->go_to_ship();
            return;
        }
        if (pirate_ptr->get_status() == status::JUNGLE) {
            continue;
        }
        if (pirate_ptr->get_coords() == m_coords) {
            pirate_ptr->go_to_ship();
        }
    }
}

void jackal::Pirate::go_to_ship() {
    Coords ship_coords = m_ship->get_coords();
    m_ship->add_pirate(this);
    m_coords = ship_coords;
}

void jackal::Pirate::stuck(int steps) {
    std::cout << "Stucked for " << steps << " steps" << std::endl;
    m_stucked_for = steps;
    m_status = status::STUCK;
}

void jackal::Pirate::die() {
    std::cout << "Pirate is dead" << std::endl;
    m_status = status::DEAD;
    m_coords = {-2, -2};
}

// Store the position last move was done
void jackal::Pirate::set_last_move(eventType type, Coords coords) {
    m_last_move = std::make_pair(type, coords);
}

jackal::status jackal::Pirate::get_status() const {
    return m_status;
}

void jackal::Pirate::set_status(status cur_status) {
    m_status = cur_status;
}

void jackal::Pirate::take_coin(int n) {
    set_status(status::CARRYING_COIN);
    m_coins = n;
}

void jackal::Pirate::get_rum(int n) {
    m_owner->get_rum_bottles(n);
}

void jackal::Pirate::drown() {
    set_status(status::DROWN);
    m_coins = 0;
}

std::pair<jackal::eventType, jackal::Coords> jackal::Pirate::get_last_move() const {
    return m_last_move;
}

jackal::Coords jackal::Pirate::get_ship_coords() const {
    return m_ship->get_coords();
}

int jackal::Pirate::drop_coin() {
    return std::exchange(m_coins, 0);
}

int jackal::Pirate::get_coins_amount() const {
    return m_coins;
}
