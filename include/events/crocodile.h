#ifndef CROCODILE_H_
#define CROCODILE_H_

#include "event.h"

namespace jackal {

    class Crocodile : public Event {
    public:
        EventType invoke(Pirate& pirate) override {
            std::cout << "Crocodile" << std::endl;
            return m_type;
        }

    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // CROCODILE_H_