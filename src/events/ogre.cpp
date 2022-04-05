#include "ogre.h"

namespace jackal {

    EventType Ogre::invoke(Pirate &pirate) {
        std::cout << "Ogre" << std::endl;
        pirate.die();
        return m_type;
    }
}