#ifndef BALLOON_H_
#define BALLOON_H_

#include "event.h"

namespace jackal {

    class Ballon : public Event {
    public:
        void invoke(Pirate &pirate) override {
            std::cout << "Balloon" << std::endl;
        }
    };

} // namespace jackal

#endif // BALLOON_H_