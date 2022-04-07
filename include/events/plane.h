#ifndef PLANE_H_
#define PLANE_H_

#include "event.h"

namespace jackal {

    class Plane : public Event {
    public:
        Plane() : filename("plane.png") {
        }

        EventType invoke(Pirate& pirate) override {
            std::cout << "Plane" << std::endl;
            return m_type;
        }

        std::string get_filename() {
            return filename;
        }

    private:
        EventType m_type = EventType::SIMPLE;
        std::string filename;
    };

} // namespace jackal

#endif // PLANE_H_