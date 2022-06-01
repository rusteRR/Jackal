#include "healer.h"

jackal::EventType jackal::Healer::invoke(jackal::Pirate &pirate) {
    std::cout << "Healer" << std::endl;
    pirate.set_status(status::PROTECTED);
    pirate.heal_dead_pirates(pirate.get_coords());
    return m_type;
}
