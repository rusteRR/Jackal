#ifndef HORSE_H_
#define HORSE_H_

#include "event.h"

namespace jackal {

    class Horse : public Event {
    public:
        EventType invoke(Pirate &pirate) override {
            std::cout << "Horse" << std::endl;
        }
    };

} // namespace jackal

#endif // HORSE_H_