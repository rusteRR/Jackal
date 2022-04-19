#include "ogre.h"

jackal::EventType jackal::Ogre::invoke(Pirate &pirate) {
    std::cout << "Ogre" << std::endl;
    pirate.die();
    return m_type;
}