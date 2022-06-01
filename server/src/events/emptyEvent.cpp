#include "emptyEvent.h"
#include <random>

jackal::EmptyEvent::EmptyEvent() : Event("", true) {
    std::mersenne_twister_engine<uint_fast32_t, 32,624,397,31,0x9908b0df,11,0xffffffff,7,0x9d2c5680,15,0xefc60000,18,1812433253> eng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distr(1, 4);
    int ind = distr(eng);
    m_filename = "emptyEvent" + std::to_string(ind) + ".png";
}

jackal::EventType jackal::EmptyEvent::invoke(jackal::Pirate &pirate) {
    std::cout << "Empty event" << std::endl;
    is_opened = true;
    return m_type;
}
