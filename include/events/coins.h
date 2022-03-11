#ifndef COINS_H_
#define COINS_H_

#include "event.h"

namespace jackal {

    class Coins : public Event {
    public:
        EventType invoke(Pirate& pirate) override {
            std::cout << "Coins" << std::endl;
            return m_type;
        }

    private:
        EventType m_type = EventType::SIMPLE;
        int amount;
    };

} // namespace jackal

#endif // COINS_H_