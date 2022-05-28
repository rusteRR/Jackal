#include "multiPointer.h"
#include "settings.h"
#include <random>

jackal::MultiPointer::MultiPointer(jackal::Settings& settings) : Event("multiPointer", true) {
    std::mersenne_twister_engine<uint_fast32_t, 32,624,397,31,0x9908b0df,11,0xffffffff,7,0x9d2c5680,15,0xefc60000,18,1812433253> eng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distr(0, 3);
    MultiPointerType type = settings.get_multi_pointer();
    if (type == MultiPointerType::DOUBLE_DIRECT) {
        auto [x, y] = Settings::get_direct_directions();
        directions.insert({{x, y}, {-x, -y}});
    }
    else if (type == MultiPointerType::DOUBLE_DIAGONAL) {
        auto [x, y] = Settings::get_diagonal_directions();
        directions.insert({{x, y}, {-x, -y}});
    }
    else if (type == MultiPointerType::QUAD_DIRECT) {
        directions.insert({{-1, 0}, {0, 1}, {0, -1}, {1, 0}});
    }
    else if (type == MultiPointerType::QUAD_DIAGONAL) {
        directions.insert({{-1, -1}, {-1, 1}, {1, -1}, {1, 1}});
    }
    else {
        auto [x, y] = Settings::get_diagonal_directions();
        directions.insert({{x, 0}, {0, y}, {-x, -y}});
    }
    for (auto elem : directions) {
        m_filename += "_" + std::to_string(elem.first) + "_" + std::to_string(elem.second);
    }
    m_filename += ".png";
}

jackal::EventType jackal::MultiPointer::invoke(jackal::Pirate &pirate) {
    std::cout << "multiPointer" << std::endl;
    is_opened = true;
    auto [cur_x, cur_y] = pirate.get_coords();
    pirate.set_last_move(eventType::MULTIPOINTER, pirate.get_coords());
    pirate.move(Coords{cur_x + directions.begin()->first, cur_y + directions.begin()->second});
    /*
    auto [new_x, new_y] = Server::get_coords;
    while (directions.find({new_x - cur_x, new_y - cur_y}) == directions.end()) {
        auto [new_x, new_y] = Server::get_coords;
    }
    pirate.move(Coords{new_x, new_y});*/
    return m_type;
}
