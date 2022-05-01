#include "crocodile.h"

jackal::EventType jackal::Crocodile::invoke(jackal::Pirate &pirate) {
    std::cout << "Crocodile" << std::endl;
    Coords last_move_coords = pirate.get_last_move().second;
    pirate.move(last_move_coords);
    return m_type;
}

jackal::Crocodile::Crocodile() : Event("crocodile.png", true) {
}
