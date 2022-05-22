#include "cannon.h"
#include "settings.h"
#include <random>

jackal::Cannon::Cannon() : Event("", true) {
    std::mersenne_twister_engine<uint_fast32_t, 32,624,397,31,0x9908b0df,11,0xffffffff,7,0x9d2c5680,15,0xefc60000,18,1812433253> eng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distr(0, 3);
    int ind = distr(eng);
    m_dcol = direct_directions[ind].first;
    m_drow = direct_directions[ind].second;
    m_filename = "cannon_" + std::to_string(m_dcol) + "_" + std::to_string(m_drow) + ".png";
}

jackal::EventType jackal::Cannon::invoke(jackal::Pirate &pirate) {
    std::cout << "Cannon" << std::endl;
    is_opened = true;
    Coords current_coords = pirate.get_coords();
    int new_col = current_coords.x + m_dcol * 12;
    int new_row = current_coords.y + m_drow * 12;
    pirate.move({new_col, new_row});
    return m_type;
}
