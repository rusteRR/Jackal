#include "treasure.h"

jackal::Treasure::Treasure() : Event("treasure.png", true) {
}

jackal::EventType jackal::Treasure::invoke(jackal::Pirate &pirate) {
    has_treasure = true;
    m_coins += 3;
    return m_type;
}


