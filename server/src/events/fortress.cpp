#include "fortress.h"


jackal::EventType jackal::Fortress::invoke(Pirate &pirate) {
    std::cout << "Fortress" << std::endl;
    is_opened = true;
    pirate.set_status(status::PROTECTED);
    return m_type;
}