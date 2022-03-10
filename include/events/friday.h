#ifndef FRIDAY_H_
#define FRIDAY_H_

#include "event.h"

namespace jackal {

    class Friday : public Event {
    public:
        EventType invoke(Pirate &pirate) override {
            std::cout << "Friday" << std::endl;
        }
    };

} // namespace jackal

#endif // FRIDAY_H_