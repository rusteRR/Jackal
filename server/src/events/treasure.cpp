#include "treasure.h"

jackal::Treasure::Treasure() : Event("treasure.png", true) {
    has_treasure = true;
    m_coins += 3;
}

jackal::EventType jackal::Treasure::invoke(jackal::Pirate &pirate) {
    std::cout << "Treasure" << std::endl;
    is_opened = true;
    return m_type;
}


