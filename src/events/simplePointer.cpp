#include "simplePointer.h"
#include <iostream>
#include <random>

namespace jackal {

    const std::vector<std::pair<int, int>> direct_directions = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
    };

    const std::vector<std::pair<int, int>> diagonal_directions = {
            {1, 1},
            {-1, -1},
            {1, -1},
            {-1, 1}
    };

    EventType SimplePointer::invoke(Pirate &pirate) {
        std::cout << "simplePointer " << std::endl;
        std::cout << pirate.get_coords().first << " " << pirate.get_coords().second << "\n";
        pirate.move(m_dcol, m_drow);
        std::cout << pirate.get_coords().first << " " << pirate.get_coords().second << "\n";
        return m_type;
    }

    SimplePointer::SimplePointer(Settings& settings) {
        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_int_distribution<int> distr(0, 3);
        int ind = distr(eng);
        SimplePointerType type = settings.get_simple_pointer();
        if (type == SimplePointerType::DIRECT) {
            m_dcol = direct_directions[ind].first;
            m_drow = direct_directions[ind].second;
        }
        else {
            m_dcol = diagonal_directions[ind].first;
            m_drow = diagonal_directions[ind].second;
        }
    }
}