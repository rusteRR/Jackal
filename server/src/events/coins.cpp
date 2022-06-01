#include "coins.h"


jackal::Coins::Coins(int n) : Event("coins", true) {
    m_coins = n;
    m_filename += std::to_string(n) + ".png";
}

jackal::EventType jackal::Coins::invoke(Pirate &pirate) {
    std::cout << "Coins" << std::endl;
    is_opened = true;
    return m_type;
}

