#ifndef FORTRESS_H_
#define FORTRESS_H_

#include "event.h"

namespace jackal {

    class Fortress : public Event {
    public:
        EventType invoke(Pirate& pirate) override {
            std::cout << "Fortress" << std::endl;
            return m_type;
        }

    private:
        EventType m_type = EventType::SIMPLE;
        bool heal;
    };

} // namespace jackal

#endif // FORTRESS_H_