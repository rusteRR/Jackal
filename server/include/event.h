#ifndef EVENT_H_
#define EVENT_H_

#include "pirate.h"
#include <iostream>
#include <string>

namespace jackal {

    enum class EventType {SIMPLE, NEW_EVENT};

    class Event {
    public:
        virtual EventType invoke(Pirate& pirate) = 0;
        virtual std::string get_filename() = 0;
        virtual ~Event() = default;
    };
    
}
#endif // EVENT_H_