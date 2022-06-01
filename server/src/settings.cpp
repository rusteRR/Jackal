#include "settings.h"
#include <random>

jackal::SimplePointerType jackal::Settings::get_simple_pointer() {
    std::mersenne_twister_engine<uint_fast32_t, 32,624,397,31,0x9908b0df,11,0xffffffff,7,0x9d2c5680,15,0xefc60000,18,1812433253> eng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distr(0, static_cast<int> (m_simple_pointer.size() - 1));
    int index = distr(eng);
    SimplePointerType type = m_simple_pointer[index].first;
    if (--m_simple_pointer[index].second == 0) {
        m_simple_pointer.erase(m_simple_pointer.begin() + index);
    }
    return type;
}

jackal::MultiPointerType jackal::Settings::get_multi_pointer() {
    std::mersenne_twister_engine<uint_fast32_t, 32,624,397,31,0x9908b0df,11,0xffffffff,7,0x9d2c5680,15,0xefc60000,18,1812433253> eng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distr(0, static_cast<int> (m_multi_pointer.size() - 1));
    int index = distr(eng);
    MultiPointerType type = m_multi_pointer[index].first;
    if (--m_multi_pointer[index].second == 0) {
        m_multi_pointer.erase(m_multi_pointer.begin() + index);
    }
    return type;
}

std::pair<int, int> jackal::Settings::get_direct_directions() {
    std::mersenne_twister_engine<uint_fast32_t, 32,624,397,31,0x9908b0df,11,0xffffffff,7,0x9d2c5680,15,0xefc60000,18,1812433253> eng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distr(0, static_cast<int> (diagonal_directions.size() - 1));
    return direct_directions[distr(eng)];
}

std::pair<int, int> jackal::Settings::get_diagonal_directions() {
    std::mersenne_twister_engine<uint_fast32_t, 32,624,397,31,0x9908b0df,11,0xffffffff,7,0x9d2c5680,15,0xefc60000,18,1812433253> eng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distr(0, static_cast<int> (diagonal_directions.size() - 1));
    return diagonal_directions[distr(eng)];
}

bool jackal::Coords::operator==(const jackal::Coords &rhs) const {
    return (x == rhs.x && y == rhs.y);
}

bool jackal::Coords::operator!=(const jackal::Coords &rhs) const {
    return (x != rhs.x || y != rhs.y);
}

