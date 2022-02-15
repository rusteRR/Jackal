#ifndef EVENT_H_
#define EVENT_H_

#include "pirate.h"

namespace jackal {

    class Event {
    public:
        virtual void move(Pirate& pirate) = 0;
        virtual ~Event() = 0;
    };

    class MoveEvent : public Event {
    public:
        void move(Pirate& pirate) override;
    };
}
#endif // EVENT_H_
