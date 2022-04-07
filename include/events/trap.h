#ifndef TRAP_H_
#define TRAP_H_

#include "event.h"

namespace jackal {

    class Trap : public Event {
    public:
        Trap() : filename("trap.png") {
        }

        EventType invoke(Pirate& pirate) override {
            std::cout << "Trap" << std::endl;
            return m_type;
        }

        std::string get_filename() override {
            return filename;
        }

    private:
        std::string filename;
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // TRAP_H_