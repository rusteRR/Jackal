#ifndef ICE_H_
#define ICE_H_

#include "event.h"

namespace jackal {

    class Ice : public Event {
    public:
        EventType invoke(Pirate& pirate) override;

    private:
        EventType m_type = EventType::NEW_EVENT;
    };

} // namespace jackal

#endif // ICE_H_