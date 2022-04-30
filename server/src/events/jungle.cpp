#include "jungle.h"

jackal::Jungle::Jungle() : Event("jungle.png", false) {

}

jackal::EventType jackal::Jungle::invoke(jackal::Pirate &pirate) {
    std::cout << "Jungle" << std::endl;
    pirate.set_status(status::JUNGLE);
    return m_type;
}
