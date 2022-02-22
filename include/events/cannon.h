#ifndef CANNON_H_
#define CANNON_H_

#include "event.h"

namespace jackal {

    class Cannon : public Event {
    public:
        void invoke(Pirate &pirate) override {
            std::cout << "Cannon" << std::endl;
        }
    };

} // namespace jackal

#endif // CANNON_H_