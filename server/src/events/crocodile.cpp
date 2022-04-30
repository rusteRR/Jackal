#include "crocodile.h"

jackal::EventType jackal::Crocodile::invoke(jackal::Pirate &pirate) {
    std::cout << "Crocodile" << std::endl;
    auto last_move_coords = pirate.get_last_move().second;
    pirate.move(last_move_coords.first, last_move_coords.second);
    return m_type;
}

jackal::Crocodile::Crocodile() : Event("crocodile.png", true) {
}
