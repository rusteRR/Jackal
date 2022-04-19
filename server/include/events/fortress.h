#ifndef FORTRESS_H_
#define FORTRESS_H_

#include "event.h"

namespace jackal {

    class Fortress : public Event {
    public:
        Fortress() : Event("fortress.png") {
        }

        EventType invoke(Pirate& pirate) override;

    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // FORTRESS_H_