#ifndef BEN_H_
#define BEN_H_

#include "event.h"

namespace jackal {

    class Ben : public Event {
    public:
        Ben() : filename("ben.png") {
        }

        EventType invoke(Pirate& pirate) override {
            std::cout << "Ben" << std::endl;
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

#endif // BEN_H_