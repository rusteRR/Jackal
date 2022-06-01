#ifndef EMPTY_EVENT_H_
#define EMPTY_EVENT_H_

#include "event.h"

namespace jackal {

    class EmptyEvent : public Event {
    public:
        EmptyEvent();

        EventType invoke(Pirate& pirate) override;

    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal


#endif // EMPTY_EVENT_H_