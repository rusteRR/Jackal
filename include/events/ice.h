#ifndef ICE_H_
#define ICE_H_

#include "event.h"

namespace jackal {

    class Ice : public Event {
    public:
        void invoke(Pirate &pirate) override {
            std::cout << "Ice" << std::endl;
        }
    };

} // namespace jackal

#endif // ICE_H_