#ifndef BOAT_H_
#define BOAT_H_

#include "event.h"

namespace jackal {

    class Boat : public Event {
    public:
        Boat() : filename("open.png") {
        }

        EventType invoke(Pirate& pirate) override {
            std::cout << "Boat" << std::endl;
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

#endif // BOAT_H_