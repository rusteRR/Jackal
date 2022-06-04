#ifndef EARTHQUAKE_H_
#define EARTHQUAKE_H_

#include "event.h"

namespace jackal {

    class Earthquake : public Event {
    public:
        Earthquake() : Event("earthquake.png", true) {
        }

        EventType invoke(Pirate& pirate) override {
            std::cout << "Earthquake" << std::endl;
            is_opened = true;
            return m_type;
        }

    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // EARTHQUAKE_H_