#ifndef LIGHTHOUSE_H_
#define LIGHTHOUSE_H_

#include "event.h"

namespace jackal {

    class Lighthouse : public Event {
    public:
        Lighthouse() : Event("lighthouse.png", true) {
        }

        EventType invoke(Pirate& pirate) override {
            std::cout << "Lighthouse" << std::endl;
            is_opened = true;
            return m_type;
        }


    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // LIGHTHOUSE_H_