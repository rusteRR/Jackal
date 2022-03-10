#ifndef PLANE_H_
#define PLANE_H_

#include "event.h"

namespace jackal {

    class Plane : public Event {
    public:
        EventType invoke(Pirate &pirate) override {
            std::cout << "Plane" << std::endl;
        }
    };

} // namespace jackal

#endif // PLANE_H_