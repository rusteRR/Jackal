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
        pirate->move(coords);
    }
    m_coords = coords;
    return true;
}

bool jackal::Ship::check_move_correctness(Coords coords) const {
    // TODO : 4 cells with coords (1, 1) ... are not water now (will be fixed(?))
    if (!(coords.x == 0 || coords.x == 12) && !(coords.y == 0 || coords.y == 12)) {
        return false;
    }
    if (abs(m_coords.x - coords.x) + abs(m_coords.y - coords.y) > 1) {
        return false;
    }
    return true;
}

void jackal::Ship::leave_ship(Pirate* pirate) {
    for (auto elem : pirates_on_board) {
        if (elem == pirate) {
            pirates_on_board.erase(std::find(pirates_on_board.begin(), pirates_on_board.end(), elem));
        }
    }
}
