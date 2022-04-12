#ifndef JUNGLE_H_
#define JUNGLE_H_

#include "event.h"

namespace jackal {

    class Jungle : public Event {
    public:
        Jungle() : filename("jungle.png") {
        }

        EventType invoke(Pirate& pirate) override {
            std::cout << "Jungle" << std::endl;
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

#endif // JUNGLE_H_