#ifndef JACKAL_WATER_H
#define JACKAL_WATER_H

#include "event.h"

namespace jackal {

    class Water : public Event {
    public:
        EventType invoke(Pirate& pirate) override{
            std::cout << "Water" << std::endl;
            return m_type;
        }

    private:
        EventType m_type = EventType::SIMPLE;
    };
}


#endif //JACKAL_WATER_H
