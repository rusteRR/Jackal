#include "water.h"

jackal::Water::Water() : Event("water.png", true) {
    is_opened = true;
}

jackal::EventType jackal::Water::invoke(jackal::Pirate &pirate) {
    std::cout << "Water" << std::endl;
    if (pirate.get_status() != status::ON_BOARD) {
        pirate.drown();
    }
    return m_type;
}
