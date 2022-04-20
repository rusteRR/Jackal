#include "coins.h"


jackal::Coins::Coins(int n) : Event("coins.png", true) {
    m_coins = n;
}

jackal::EventType jackal::Coins::invoke(Pirate &pirate) {
    std::cout << "Coins" << std::endl;
    is_opened = true;
    return m_type;
}

