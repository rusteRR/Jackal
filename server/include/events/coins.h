#ifndef COINS_H_
#define COINS_H_

#include "event.h"

namespace jackal {

    class Coins : public Event {
    public:
        Coins() : filename("coins.png") {
        }

        EventType invoke(Pirate& pirate) override {
            std::cout << "Coins" << std::endl;
            return m_type;
        }

        std::string get_filename() override {
            return filename;
        }

    private:
        std::string filename;
        EventType m_type = EventType::SIMPLE;
        int amount;
    };

} // namespace jackal

#endif // COINS_H_