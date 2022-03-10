#ifndef BOAT_H_
#define BOAT_H_

#include "event.h"

namespace jackal {

    class Boat : public Event {
    public:
        EventType invoke(Pirate &pirate) override {
            std::cout << "Boat" << std::endl;
        }
    };

} // namespace jackal

#endif // BOAT_H_