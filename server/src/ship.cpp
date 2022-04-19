#include "ship.h"


jackal::Ship::Ship(int col, int row) : m_col(col), m_row(row) {
}

std::pair<int, int> jackal::Ship::get_coords() {
    return {m_col, m_row};
}
