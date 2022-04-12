#ifndef EARTHQUAKE_H_
#define EARTHQUAKE_H_

#include "event.h"

namespace jackal {

    class Earthquake : public Event {
    public:
        Earthquake() : filename("earthquake.png") {
        }

        EventType invoke(Pirate& pirate) override {
            std::cout << "Earthquake" << std::endl;
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

#endif // EARTHQUAKE_H_