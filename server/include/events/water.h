#ifndef JACKAL_WATER_H
#define JACKAL_WATER_H

#include "event.h"

namespace jackal {

    class Water : public Event {
    public:
        Water();

        EventType invoke(Pirate& pirate) override;

    private:
        EventType m_type = EventType::SIMPLE;
    };
}


#endif //JACKAL_WATER_H
