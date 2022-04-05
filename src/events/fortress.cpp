#include "fortress.h"

namespace jackal {

    EventType Fortress::invoke(Pirate &pirate) {
        std::cout << "Fortress" << std::endl;
        pirate.set_status(status::PROTECTED);
        return m_type;
    }
}