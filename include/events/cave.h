#ifndef CAVE_H_
#define CAVE_H_

#include "event.h"

namespace jackal {

    class Cave : public Event {
    public:
        Cave() : filename("cave.png") {
        }

        EventType invoke(Pirate& pirate) override {
            std::cout << "Cave" << std::endl;
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

#endif // CAVE_H_