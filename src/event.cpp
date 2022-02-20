#include "event.h"


namespace jackal {

    SimplePointer::SimplePointer(int d_row, int d_col) : m_drow(d_row), m_dcol(d_col) {
    }

    void SimplePointer::invoke(Pirate &pirate) {
        pirate.move(m_drow, m_dcol);
    }


}
