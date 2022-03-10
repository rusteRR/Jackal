#ifndef FORTRESS_H_
#define FORTRESS_H_

#include "event.h"

namespace jackal {

    class Fortress : public Event {
    public:
        EventType invoke(Pirate &pirate) override {
            std::cout << "Fortress" << std::endl;
        }

    private:
        bool heal;
    };

} // namespace jackal

#endif // FORTRESS_H_