#ifndef BEN_H_
#define BEN_H_

#include "event.h"

namespace jackal {

    class Ben : public Event {
    public:
        EventType invoke(Pirate &pirate) override {
            std::cout << "Ben" << std::endl;
        }
    };

} // namespace jackal

#endif // BEN_H_