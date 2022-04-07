#ifndef BALLOON_H_
#define BALLOON_H_

#include "event.h"

namespace jackal {

    class Ballon : public Event {
    public:
        Ballon() : filename("balloon.png") {
        };

        EventType invoke(Pirate& pirate) override {
            std::cout << "Balloon" << std::endl;
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

#endif // BALLOON_H_