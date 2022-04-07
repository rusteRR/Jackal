#ifndef CANNON_H_
#define CANNON_H_

#include "event.h"

namespace jackal {

    class Cannon : public Event {
    public:
        Cannon() : filename("cannon.png") {
        }

        EventType invoke(Pirate& pirate) override {
            std::cout << "Cannon" << std::endl;
            return m_type;
        }

        std::string get_filename() {
            return filename;
        }

    private:
        std::string filename;
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // CANNON_H_