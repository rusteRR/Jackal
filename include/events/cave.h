#ifndef CAVE_H_
#define CAVE_H_

#include "event.h"

namespace jackal {

    class Cave : public Event {
    public:
        void invoke(Pirate &pirate) override {
            std::cout << "Cave" << std::endl;
        }
    };

} // namespace jackal

#endif // CAVE_H_