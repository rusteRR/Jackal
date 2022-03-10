#ifndef TREASURE_H_
#define TREASURE_H_

#include "event.h"

namespace jackal {

    class Treasure : public Event {
    public:
        EventType invoke(Pirate &pirate) override {
            std::cout << "Treasure" << std::endl;
        }
    };

} // namespace jackal

#endif // TREASURE_H_