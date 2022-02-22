#ifndef EVENT_H_
#define EVENT_H_

#include "pirate.h"
#include "iostream"

namespace jackal {

    class Event {
    public:
        virtual void invoke(Pirate &pirate) = 0;
        virtual ~Event() = default;
    };
    
}
#endif // EVENT_H_
