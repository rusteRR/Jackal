#include "coins.h"


jackal::Coins::Coins(int n) : Event("coins.png") {
    m_coins = n;
}

jackal::EventType jackal::Coins::invoke(Pirate &pirate) {
    return m_type;
}

