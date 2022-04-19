#ifndef FRIDAY_H_
#define FRIDAY_H_

#include "event.h"

namespace jackal {

    class Friday : public Event {
    public:
        Friday() : Event("friday.png", true) {
        }

        EventType invoke(Pirate& pirate) override {
            std::cout << "Friday" << std::endl;
            return m_type;
        }

    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // FRIDAY_H_