#ifndef EARTHQUAKE_H_
#define EARTHQUAKE_H_

#include "event.h"

namespace jackal {

    class Earthquake : public Event {
    public:
        void invoke(Pirate &pirate) override {
            std::cout << "Earthquake" << std::endl;
        }
    };

} // namespace jackal

#endif // EARTHQUAKE_H_