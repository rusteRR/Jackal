#ifndef RUM_H_
#define RUM_H_

#include "event.h"

namespace jackal {

    class Rum : public Event {
    public:
        Rum() : filename("rum-1.png") {
        }

        EventType invoke(Pirate& pirate) override {
            std::cout << "Rum" << std::endl;
            return m_type;
        }

        std::string get_filename() override {
            return filename;
        }

    private:
        EventType m_type = EventType::SIMPLE;
        std::string filename;
        int count = 0;
    };

} // namespace jackal

#endif // RUM_H_