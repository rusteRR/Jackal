#include "horse.h"

jackal::EventType jackal::Horse::invoke(Pirate& pirate) {
    std::cout << "Horse" << std::endl;
    is_opened = true;
    Coords cur_coords = pirate.get_coords();
    pirate.set_last_move(eventType::HORSE, cur_coords);
    /*
    auto [new_x, new_y] = Server::get_coords;
    while (!check_move_correctness(cur_coords, Coords{new_x, new_y})) {
        auto [new_x, new_y] = Server::get_coords;
    }
    pirate.move(Coords{new_x, new_y});
    */
    return m_type;
}

bool jackal::Horse::check_move_correctness(Coords cur_coords, Coords new_coords) {
    return ((abs(cur_coords.x - new_coords.x) == 2 && abs(cur_coords.y - new_coords.y) == 1) ||
            (abs(cur_coords.x - new_coords.x) == 1 && abs(cur_coords.y - new_coords.y) == 2));
}