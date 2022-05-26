#ifndef HEALER_H_
#define HEALER_H_

#include "event.h"

namespace jackal {

    class Healer : public Event {
    public:
        Healer() : Event("healer.png", false) {
        }

        EventType invoke(Pirate& pirate) override;

    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // HEALER_H_