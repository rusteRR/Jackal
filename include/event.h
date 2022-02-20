#ifndef EVENT_H_
#define EVENT_H_

#include "pirate.h"

namespace jackal {

    class Event {
    public:
        virtual void invoke(Pirate &pirate) = 0;
        virtual ~Event() = 0;
    };
    
}
#endif // EVENT_H_
