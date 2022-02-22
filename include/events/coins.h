#ifndef COINS_H_
#define COINS_H_

#include "event.h"

namespace jackal {

    class Coins : public Event {
    public:
        void invoke(Pirate &pirate) override {
            std::cout << "Coins" << std::endl;
        }

    private:
        int amount;
    };

} // namespace jackal

#endif // COINS_H_