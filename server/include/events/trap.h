#ifndef TRAP_H_
#define TRAP_H_

#include "event.h"

namespace jackal {

    class Trap : public Event {
    public:
        Trap() : Event("trap.png", true) {
        }

        EventType invoke(Pirate& pirate) override {
            std::cout << "Trap" << std::endl;
            return m_type;
        }


    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // TRAP_H_