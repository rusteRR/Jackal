#ifndef JACKAL_WATER_H
#define JACKAL_WATER_H

#include "event.h"

namespace jackal {

    class Water : public Event {
    public:
        Water() : filename("water.png") {
        }

        EventType invoke(Pirate& pirate) override{
            std::cout << "Water" << std::endl;
            return m_type;
        }

        std::string get_filename() override {
            return filename;
        }

    private:
        EventType m_type = EventType::SIMPLE;
        std::string filename;
    };
}


#endif //JACKAL_WATER_H
