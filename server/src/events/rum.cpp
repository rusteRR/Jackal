#include "rum.h"

jackal::Rum::Rum(int n) : Event("rum", true), bottles(n) {
    m_filename += std::to_string(n) + ".png";
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
