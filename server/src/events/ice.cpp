#include "ice.h"

namespace jackal {

    EventType Ice::invoke(Pirate &pirate) {
        std::cout << "Ice" << std::endl;
        pirate.ice();
        return m_type;
    }
}