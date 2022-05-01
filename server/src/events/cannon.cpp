#include "cannon.h"
#include <random>

const std::vector<std::pair<int, int>> direct_directions = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
};

jackal::Cannon::Cannon() : Event("", true) {
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(0, 3);
    int ind = distr(eng);
    m_dcol = direct_directions[ind].first;
    m_drow = direct_directions[ind].second;
    m_filename = "cannon_" + std::to_string(m_dcol) + "_" + std::to_string(m_drow) + ".png";
}

jackal::EventType jackal::Cannon::invoke(jackal::Pirate &pirate) {
    std::cout << "Cannon" << std::endl;
    auto current_coords = pirate.get_coords();
    int new_col = current_coords.first + m_dcol * 12;
    int new_row = current_coords.second + m_drow * 12;
    pirate.move(new_col, new_row);
    return m_type;
}
