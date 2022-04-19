#include "spinner.h"


jackal::EventType jackal::Spinner::invoke(Pirate& pirate) {
    pirate.stuck(m_cnt);
    return m_type;
}

jackal::Spinner::Spinner(int n) : Event("spinner.png"), m_cnt(n) {
}