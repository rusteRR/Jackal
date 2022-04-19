#include "spinner.h"


jackal::EventType jackal::Spinner::invoke(Pirate& pirate) {
    std::cout << "Spinner" << std::endl;
    pirate.stuck(m_cnt);
    return m_type;
}

jackal::Spinner::Spinner(int n) : Event("spinner.png", true), m_cnt(n) {
}