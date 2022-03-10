#ifndef CART_H_
#define CART_H_

#include "event.h"

namespace jackal {

    class Cart : public Event {
    public:
        EventType invoke(Pirate &pirate) override {
            std::cout << "Cart" << std::endl;
        };
    };

} // namespace jackal

#endif // CART_H_