#ifndef OGRE_H_
#define OGRE_H_

#include "event.h"

namespace jackal {

    class Ogre : public Event {
    public:
        EventType invoke(Pirate &pirate) override {
            std::cout << "Ogre" << std::endl;
        }
    };

} // namespace jackal

#endif // OGRE_H_