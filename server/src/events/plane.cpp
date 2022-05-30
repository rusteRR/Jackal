#include "plane.h"

jackal::Plane::Plane() : Event("plane.png", true) {
}

jackal::EventType jackal::Plane::invoke(jackal::Pirate &pirate) {
    std::cout << "Plane" << std::endl;
    if (!is_opened) {

    }
    is_opened = true;
    return m_type;
}

bool jackal::Plane::check_move_correctness(Coords new_coords) {
    return (new_coords.x > COORD_LOWER_BOUND && new_coords.x < COORD_UPPER_BOUND &&
            new_coords.y > COORD_LOWER_BOUND && new_coords.y < COORD_UPPER_BOUND);
}

