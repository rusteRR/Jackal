#ifndef CANNON_H_
#define CANNON_H_

#include "event.h"

namespace jackal {

    class Cannon : public Event {
    public:
        EventType invoke(Pirate& pirate) override {
            std::cout << "Cannon" << std::endl;
            return m_type;
        }

    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // CANNON_H_