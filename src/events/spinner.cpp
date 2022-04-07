#include "spinner.h"

namespace jackal {

    EventType Spinner::invoke(Pirate& pirate) {
        pirate.stuck(m_cnt);
        return m_type;
    }

    Spinner::Spinner(int n) : m_cnt(n), filename("spinner.png") {
    }
}