#ifndef MISSIONARY_H_
#define MISSIONARY_H_

#include "event.h"

namespace jackal {

    class Missionary : public Event {
    public:
        Missionary() : filename("missionary.png") {
        }

        EventType invoke(Pirate& pirate) override {
            std::cout << "Missionary" << std::endl;
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

#endif // MISSIONARY_H_