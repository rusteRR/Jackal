#ifndef EMPTY_EVENT_H_
#define EMPTY_EVENT_H_

#include "event.h"

namespace jackal {

    class EmptyEvent : public Event {
    public:
        EmptyEvent() : Event("emptyEvent.png") {
        }

        EventType invoke(Pirate& pirate) override {
            std::cout << "EmptyEvent" << std::endl;
            return m_type;
        }

    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal


#endif // EMPTY_EVENT_H_