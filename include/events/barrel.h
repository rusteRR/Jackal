#ifndef BARREL_H_
#define BARREL_H_

#include "event.h"

namespace jackal {

    class Barrel : public Event {
    public:
        EventType invoke(Pirate& pirate) override {
            std::cout << "Barrel" << std::endl;
            return m_type;
        }

    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // BARREL_H_