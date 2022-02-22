#ifndef MISSIONARY_H_
#define MISSIONARY_H_

#include "event.h"

namespace jackal {

    class Missionary : public Event {
    public:
        void invoke(Pirate &pirate) override {
            std::cout << "Missionary" << std::endl;
        }
    };

} // namespace jackal

#endif // MISSIONARY_H_