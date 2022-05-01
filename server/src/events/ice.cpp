#include "ice.h"


jackal::EventType jackal::Ice::invoke(Pirate &pirate) {
    std::cout << "Ice" << std::endl;
    is_opened = true;
    auto last_move = pirate.get_last_move();
    Coords cur_coords = pirate.get_coords();
    if (last_move.first == eventType::SIMPLE) {
        Coords last_move_coords = last_move.second;
        pirate.move({cur_coords.x + (cur_coords.x - last_move_coords.x),
                    cur_coords.y + (cur_coords.y - last_move_coords.y)});
    }
    return m_type;
}
