#include "plane.h"

jackal::Plane::Plane() : Event("plane.png", true) {
}

jackal::EventType jackal::Plane::invoke(jackal::Pirate &pirate) {
    std::cout << "Plane" << std::endl;
    pirate.set_last_move(eventType::PLANE, pirate.get_coords());
    if (!is_opened) {
        std::uniform_int_distribution<int> distr(1, COORD_UPPER_BOUND - 1);
        int x = distr(eng1);
        int y = distr(eng1);
        pirate.move(Coords{x, y});
    }
    is_opened = true;
    return m_type;
}

bool jackal::Plane::check_move_correctness(Coords new_coords) {
    return (new_coords.x > COORD_LOWER_BOUND && new_coords.x < COORD_UPPER_BOUND &&
            new_coords.y > COORD_LOWER_BOUND && new_coords.y < COORD_UPPER_BOUND);
}

