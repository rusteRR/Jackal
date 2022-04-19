#include "event.h"


std::string jackal::Event::get_filename() {
    return m_filename;
}

jackal::Event::Event(const std::string &file) : m_filename(file), m_coins(0), is_opened(false) {
}

bool jackal::Event::take_coin(Pirate& pirate) {
    if (m_coins && pirate.get_status() != status::CARRYING_COIN) {
        m_coins--;
        pirate.set_status(status::CARRYING_COIN);
        return true;
    }
    return false;
}
