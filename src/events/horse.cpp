#include "horse.h"

namespace jackal {

    EventType Horse::invoke(Pirate &pirate) {
        std::pair<int, int> response = get_response();
        return m_type;
    }
}