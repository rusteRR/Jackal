#ifndef OGRE_H_
#define OGRE_H_

#include "event.h"

namespace jackal {

    class Ogre : public Event {
    public:
        EventType invoke(Pirate& pirate) override;

    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // OGRE_H_