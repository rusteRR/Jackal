#include "ship.h"

namespace jackal {

    Ship::Ship(int col, int row) : m_col(col), m_row(row) {
    }

    std::pair<int, int> Ship::get_coords() {
        return {m_col, m_row};
    }

    //void Ship::shipMove() {}

}
