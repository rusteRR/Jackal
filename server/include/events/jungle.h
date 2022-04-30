#ifndef JUNGLE_H_
#define JUNGLE_H_

#include "event.h"

namespace jackal {

    class Jungle : public Event {
    public:
        Jungle();
        EventType invoke(Pirate& pirate) override;

    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // JUNGLE_H_