#ifndef CROCODILE_H_
#define CROCODILE_H_

#include "event.h"

namespace jackal {

    class Crocodile : public Event {
    public:
        EventType invoke(Pirate &pirate) override {
            std::cout << "Crocodile" << std::endl;
        }
    };

} // namespace jackal

#endif // CROCODILE_H_