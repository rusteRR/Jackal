#include "ship.h"
#include <iostream>
#include <algorithm>


jackal::Ship::Ship(int col, int row) : m_coords({col, row}) {
}

jackal::Coords jackal::Ship::get_coords() const {
    return m_coords;
}

void jackal::Ship::add_pirate(Pirate* pirate) {
    pirates_on_board.push_back(pirate);
}

bool jackal::Ship::move(Coords coords) {
    if (!check_move_correctness(coords) || pirates_on_board.empty()) {
        return false;
    }
    for (const auto& pirate : pirates_on_board) {
        pirate->move(coords, moveType::SHIP_MOVE);
    }
    m_coords = coords;
    return true;
}

bool jackal::Ship::check_move_correctness(Coords coords) const {
    if (!(coords.x == 0 || coords.x == 12) && !(coords.y == 0 || coords.y == 12)) {
        return false;
    }
    if (abs(m_coords.x - coords.x) + abs(m_coords.y - coords.y) > 1) {
        return false;
    }
    if ((coords.x > 10 || coords.x < 2) && (coords.y > 10 || coords.y < 2)) {
        return false;
    }
    return true;
}

void jackal::Ship::leave_ship(Pirate* pirate) {
    std::vector<Pirate*> pirates;
    for (auto elem : pirates_on_board) {
        if (elem != pirate) {
            pirates.push_back(elem);
        }
    }
    pirates_on_board = pirates;
}
