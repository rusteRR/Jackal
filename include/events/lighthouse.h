#ifndef LIGHTHOUSE_H_
#define LIGHTHOUSE_H_

#include "event.h"

namespace jackal {

    class Lighthouse : public Event {
    public:
        EventType invoke(Pirate &pirate) override {
            std::cout << "Lighthouse" << std::endl;
        }
    };

} // namespace jackal

#endif // LIGHTHOUSE_H_