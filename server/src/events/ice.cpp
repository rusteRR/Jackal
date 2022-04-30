#include "ice.h"


jackal::EventType jackal::Ice::invoke(Pirate &pirate) {
    std::cout << "Ice" << std::endl;
    is_opened = true;
    auto last_move = pirate.get_last_move();
    auto cur_coords = pirate.get_coords();
    if (last_move.first == eventType::SIMPLE) {
        auto last_move_coords = last_move.second;
        pirate.move(cur_coords.first + (cur_coords.first - last_move_coords.first),
                    cur_coords.second + (cur_coords.second - last_move_coords.second));
    }
    return m_type;
}
