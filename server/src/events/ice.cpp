#include "ice.h"


jackal::EventType jackal::Ice::invoke(Pirate &pirate) {
    std::cout << "Ice" << std::endl;
    is_opened = true;
    pirate.ice();
    return m_type;
}
