#include "pirate.h"

namespace jackal {
    void Pirate::move(int d_col, int d_row) {
        m_col += d_col;
        m_row += d_row;
    }

    std::pair<int, int> Pirate::get_coords() const {
        return {m_col, m_row};
    }
}