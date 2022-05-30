#include "spinner.h"


jackal::EventType jackal::Spinner::invoke(Pirate& pirate) {
    std::cout << "Spinner" << std::endl;
    is_opened = true;
    if (!pirate.try_to_escape()) {
        pirate.stuck(m_cnt);
    }
    return m_type;
}

jackal::Spinner::Spinner(int n) : Event("spinner", true), m_cnt(n) {
    m_filename += std::to_string(n) + ".png";
}