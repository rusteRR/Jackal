#ifndef COINS_H_
#define COINS_H_

#include "event.h"

namespace jackal {

    class Coins : public Event {
    public:
        explicit Coins(int n);

        EventType invoke(Pirate& pirate) override;

    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // COINS_H_