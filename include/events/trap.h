#ifndef TRAP_H_
#define TRAP_H_

#include "event.h"

namespace jackal {

    class Trap : public Event {
    public:
        void invoke(Pirate &pirate) override {
            std::cout << "Trap" << std::endl;
        }
    };

} // namespace jackal

#endif // TRAP_H_