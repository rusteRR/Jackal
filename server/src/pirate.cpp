#include "pirate.h"
#include "game.h"
#include <vector>
#include <iostream>
#include <memory>



jackal::Pirate::Pirate(int col, int row, Ship *ship, Player* owner) :
                    m_col(col), m_row(row), m_coins(0),
                    m_status(status::ALIVE), m_ship(ship), m_owner(owner) {
}


// Make move from cuurent position to position (col, row)
void jackal::Pirate::move(int col, int row) {
    if (m_status == status::ON_BOARD) {
        m_ship->leave_ship(this);
        m_status = status::ALIVE;
    }
    if (col > COORD_UPPER_BOUND) col = COORD_UPPER_BOUND;
    else if (col < COORD_LOWER_BOUND) col = COORD_LOWER_BOUND;
    if (row > COORD_UPPER_BOUND) row = COORD_UPPER_BOUND;
    else if (row < COORD_LOWER_BOUND) row = COORD_LOWER_BOUND;
    m_col = col;
    m_row = row;
    if (get_coords() == m_ship->get_coords()) {
        m_owner->increase_coins(m_coins);
        m_coins = 0;
    }
}

std::pair<int, int> jackal::Pirate::get_coords() const {
    return {m_col, m_row};
}

void jackal::Pirate::attack_pirate(Game &game) {
    // TODO : wrong pirate coords - should fix
    // TODO : fix killing pirate in jungle
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

void jackal::Pirate::go_to_ship() {
    std::pair<int, int> ship_coords = m_ship->get_coords();
    m_col = ship_coords.first;
    m_row = ship_coords.second;
}

void jackal::Pirate::stuck(int steps) {
    std::cout << "STUCKED FOR " << steps << " STEPS" << std::endl;
    m_stucked_for = steps;
    m_status = status::STUCK;
}

void jackal::Pirate::die() {
    std::cout << "DEAD" << std::endl;
    m_status = status::DEAD;
}

// Store the position last move was done
void jackal::Pirate::set_last_move(eventType type, int col, int row) {
    m_last_move = std::make_pair(type, std::make_pair(col, row));
}

jackal::status jackal::Pirate::get_status() const {
    return m_status;
}

void jackal::Pirate::set_status(status cur_status) {
    m_status = cur_status;
}

void jackal::Pirate::take_coin(int n) {

}

void jackal::Pirate::get_rum(int n) {
    m_owner->get_rum_bottles(n);
}

void jackal::Pirate::drown() {
    set_status(status::DROWN);
    m_coins = 0;
}

std::pair<jackal::eventType, std::pair<int, int>> jackal::Pirate::get_last_move() const {
    return m_last_move;
}
