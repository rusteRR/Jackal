#include "rum.h"

jackal::Rum::Rum() : Event("rum-1.png"), bottles(1) {
}

jackal::EventType jackal::Rum::invoke(jackal::Pirate &pirate) {
    if (bottles) {
        pirate.get_rum(bottles);
        bottles = 0;
    }
    return m_type;
}
