#ifndef GRASS_H_
#define GRASS_H_

#include "event.h"

namespace jackal {

    class Grass : public Event {
    public:
        EventType invoke(Pirate &pirate) override {
            std::cout << "Grass" << std::endl;
        }
    };

} // namespace jackal

#endif // GRASS_H_