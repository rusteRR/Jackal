#ifndef TREASURE_H_
#define TREASURE_H_

#include "event.h"

namespace jackal {

    class Treasure : public Event {
    public:
        Treasure() : Event("treasure.png", true) {
        }

        EventType invoke(Pirate& pirate) override {
            std::cout << "Treasure" << std::endl;
            return m_type;
        }


    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // TREASURE_H_