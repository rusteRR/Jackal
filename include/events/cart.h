#ifndef CART_H_
#define CART_H_

#include "event.h"

namespace jackal {

    class Cart : public Event {
    public:
        EventType invoke(Pirate& pirate) override {
            std::cout << "Cart" << std::endl;
            return m_type;
        }

    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // CART_H_