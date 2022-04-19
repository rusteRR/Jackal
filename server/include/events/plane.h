#ifndef PLANE_H_
#define PLANE_H_

#include "event.h"

namespace jackal {

    class Plane : public Event {
    public:
        Plane() : Event("plane.png") {
        }

        EventType invoke(Pirate& pirate) override {
            std::cout << "Plane" << std::endl;
            return m_type;
        }


    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // PLANE_H_