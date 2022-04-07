#ifndef CART_H_
#define CART_H_

#include "event.h"

namespace jackal {

    class Cart : public Event {
    public:
        Cart() : filename("open.png") {
        }

        EventType invoke(Pirate& pirate) override {
            std::cout << "Cart" << std::endl;
            return m_type;
        }

        std::string get_filename() {
            return filename;
        }

    private:
        std::string filename;
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // CART_H_