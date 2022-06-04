#ifndef CAVE_H_
#define CAVE_H_

#include "event.h"

namespace jackal {

    class Cave : public Event {
    public:
        Cave() : Event("cave.png", true) {
        }

        EventType invoke(Pirate& pirate) override {
            std::cout << "Cave" << std::endl;
            is_opened = true;
            return m_type;
        }

    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // CAVE_H_