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
    std::random_device rd;
    std::default_random_engine eng(rd());
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