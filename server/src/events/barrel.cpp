#include "barrel.h"

namespace {
    constexpr int DRUNK_STEPS_FOR = 1;
}

jackal::Barrel::Barrel() : Event("barrel.png", true) {
}

jackal::EventType jackal::Barrel::invoke(jackal::Pirate &pirate) {
    std::cout << "Barrel" << std::endl;
    is_opened = true;
    pirate.drunk(DRUNK_STEPS_FOR + 1);
    return m_type;
}
