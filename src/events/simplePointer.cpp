#include "simplePointer.h"

namespace jackal {

    EventType SimplePointer::invoke(Pirate &pirate) {
        std::cout << "simplePointer" << std::endl;
        pirate.move(m_dcol, m_drow);
        return m_type;
    }
}