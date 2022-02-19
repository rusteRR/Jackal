#include "pirate.h"

namespace jackal {
    void Pirate::move(int d_row, int d_col) {
        m_col += d_col;
        m_row += d_row;
    }
}