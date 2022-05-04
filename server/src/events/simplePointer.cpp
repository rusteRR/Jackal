#include "simplePointer.h"
#include <iostream>
#include <string>
#include <random>

jackal::EventType jackal::SimplePointer::invoke(Pirate &pirate) {
    std::cout << "simplePointer " << std::endl;
    is_opened = true;
    Coords cur_coords = pirate.get_coords();
    pirate.set_last_move(eventType::SIMPLE, cur_coords);
    cur_coords.x += m_dcol;
    cur_coords.y += m_drow;
    pirate.move(cur_coords);
    return m_type;
}

jackal::SimplePointer::SimplePointer(Settings& settings) : Event("", true) {
    std::mersenne_twister_engine<uint_fast32_t, 32,624,397,31,0x9908b0df,11,0xffffffff,7,0x9d2c5680,15,0xefc60000,18,1812433253> eng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distr(0, 3);
    int ind = distr(eng);
    SimplePointerType type = settings.get_simple_pointer();
    if (type == SimplePointerType::DIRECT) {
        m_dcol = direct_directions[ind].first;
        m_drow = direct_directions[ind].second;
    } else {
        m_dcol = diagonal_directions[ind].first;
        m_drow = diagonal_directions[ind].second;
    }
    m_filename = "simplePointer_" + std::to_string(m_dcol) + "_" + std::to_string(m_drow) + ".png";
}
