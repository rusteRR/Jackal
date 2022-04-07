#ifndef BARREL_H_
#define BARREL_H_

#include "event.h"

namespace jackal {

    class Barrel : public Event {
    public:
        Barrel() : filename("open.png") {
        }

        EventType invoke(Pirate& pirate) override {
            std::cout << "Barrel" << std::endl;
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

#endif // BARREL_H_