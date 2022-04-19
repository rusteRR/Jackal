#include "event.h"


std::string jackal::Event::get_filename() {
    return m_filename;
}

jackal::Event::Event(const std::string &file, bool is_av) : m_filename(file), m_coins(0),
                                            is_opened(false), m_is_available_with_coin(is_av) {
}

bool jackal::Event::take_coin(Pirate& pirate) {
    if (m_coins && pirate.get_status() != status::CARRYING_COIN) {
        pirate.take_coin(1);
        m_coins--;
        return true;
    }
    return false;
}

bool jackal::Event::opened_status() const {
    return is_opened;
}

bool jackal::Event::is_available_with_coin() const {
    return m_is_available_with_coin;
}
