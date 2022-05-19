#include "rum.h"

jackal::Rum::Rum() : Event("rum-1.png", true), bottles(1) {
}

jackal::EventType jackal::Rum::invoke(jackal::Pirate &pirate) {
    std::cout << "Rum" << std::endl;
    is_opened = true;
    if (bottles) {
        pirate.pick_up_rum(bottles);
        bottles = 0;
    }
    return m_type;
}
