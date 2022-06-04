#include "event.h"
#include <random>


std::string jackal::Event::get_filename() {
    return m_filename;
}

jackal::Event::Event(const std::string &file, bool is_av) : m_filename(file), m_coins(0),
                                            is_opened(false), m_is_available_with_coin(is_av),
                                            has_treasure(false),
                                            eng1(std::chrono::steady_clock::now().time_since_epoch().count()) {
}

bool jackal::Event::take_coin(Pirate& pirate, int coins_to_take) {
    if (m_coins < coins_to_take || pirate.get_status() == status::CARRYING_COIN ||
                    (coins_to_take == 3 && !has_treasure)) {
        return false;
    }
    if (coins_to_take == 3) {
        has_treasure = false;
    }
    pirate.take_coin(coins_to_take);
    m_coins -= coins_to_take;
    return true;
}

bool jackal::Event::opened_status() const {
    return is_opened;
}

bool jackal::Event::is_available_with_coin() const {
    return m_is_available_with_coin;
}

void jackal::Event::increase_coins(int n) {
    if (n == 3) {
        has_treasure = true;
    }
    m_coins += n;
}

int jackal::Event::get_coins_amount() const {
    return m_coins;
}
