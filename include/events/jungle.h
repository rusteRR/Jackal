#ifndef JUNGLE_H_
#define JUNGLE_H_

#include "event.h"

namespace jackal {

    class Jungle : public Event {
    public:
        EventType invoke(Pirate &pirate) override {
            std::cout << "Jungle" << std::endl;
        }
    };

} // namespace jackal

#endif // JUNGLE_H_