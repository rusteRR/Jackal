#include "ship.h"
#include <iostream>
#include <algorithm>


jackal::Ship::Ship(int col, int row) : m_col(col), m_row(row) {
}

std::pair<int, int> jackal::Ship::get_coords() {
    return {m_col, m_row};
}

void jackal::Ship::add_pirate(const std::shared_ptr<jackal::Pirate>& pirate) {
    pirates_on_board.push_back(pirate);
}

void jackal::Ship::move(int col, int row) {
    if (!check_move_correctness(col, row)) {
        std::cout << "Incorrect ship move!" << std::endl;
        return;
    }
    for (const auto& pirate : pirates_on_board) {
        pirate->move(col, row);
    }
    m_row = row;
    m_col = col;
}

bool jackal::Ship::check_move_correctness(int col, int row) const {
    // TODO : 4 cells with coords (1, 1) ... are not water now (will be fixed(?))
    if (!(col == 0 || col == 12) && !(row == 0 || row == 12)) {
        return false;
    }
    if (abs(m_col - col) + abs(m_row - row) > 1) {
        return false;
    }
    return true;
}

void jackal::Ship::leave_ship(Pirate* pirate) {
    for (const auto& elem : pirates_on_board) {
        if (elem.get() == pirate) {
            pirates_on_board.erase(std::find(pirates_on_board.begin(), pirates_on_board.end(), elem));
        }
    }
}
