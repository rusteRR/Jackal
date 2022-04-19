#include "water.h"

jackal::Water::Water() : Event("water.png", true) {
}

jackal::EventType jackal::Water::invoke(jackal::Pirate &pirate) {
    std::cout << "Water" << std::endl;
    pirate.drown();
    return m_type;
}


