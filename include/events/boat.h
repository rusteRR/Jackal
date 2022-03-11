#ifndef BOAT_H_
#define BOAT_H_

#include "event.h"

namespace jackal {

    class Boat : public Event {
    public:
        EventType invoke(Pirate& pirate) override {
            std::cout << "Boat" << std::endl;
            return m_type;
        }

    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // BOAT_H_