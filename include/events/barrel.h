#ifndef BARREL_H_
#define BARREL_H_

#include "event.h"

namespace jackal {

    class Barrel : public Event {
    public:
        void invoke(Pirate &pirate) override {
            std::cout << "Barrel" << std::endl;
        }
    };

} // namespace jackal

#endif // BARREL_H_