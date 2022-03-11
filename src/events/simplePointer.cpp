#include "simplePointer.h"
#include <iostream>
#include <random>

namespace jackal {

    EventType SimplePointer::invoke(Pirate &pirate) {
        std::cout << "simplePointer" << std::endl;
        pirate.move(m_dcol, m_drow);
        return m_type;
    }

    SimplePointer::SimplePointer() {
        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_int_distribution<int> distr(-1, 1);
        m_dcol = distr(eng);
        m_drow = distr(eng);
    }
}