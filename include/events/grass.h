#ifndef GRASS_H_
#define GRASS_H_

#include "event.h"

namespace jackal {

    class Grass : public Event {
    public:
        EventType invoke(Pirate& pirate) override {
            std::cout << "Grass" << std::endl;
            return m_type;
        }

    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // GRASS_H_