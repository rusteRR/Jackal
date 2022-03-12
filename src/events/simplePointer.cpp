#include "simplePointer.h"
#include <iostream>
#include <random>

namespace jackal {


    EventType SimplePointer::invoke(Pirate &pirate) {
        std::cout << "simplePointer" << std::endl;
        pirate.move(m_dcol, m_drow);
        return m_type;
    }

    SimplePointer::SimplePointer(Settings& settings) {
        SimplePointerType type = settings.get_simple_pointer();
        if (type == SimplePointerType::DIRECT) {
            // TODO
        }
        else {
            // TODO
        }
    }
}