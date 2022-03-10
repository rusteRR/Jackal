#ifndef EMPTY_EVENT_H_
#define EMPTY_EVENT_H_

#include "event.h"

namespace jackal {
    class EmptyEvent : public Event {
    public:
        EventType invoke(Pirate &pirate) override {
            std::cout << "EmptyEvent" << std::endl;
        }
    };

} // namespace jackal


#endif // EMPTY_EVENT_H_