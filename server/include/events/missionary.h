#ifndef MISSIONARY_H_
#define MISSIONARY_H_

#include "event.h"

namespace jackal {

    class Missionary : public Event {
    public:
        Missionary() : Event("missionary.png") {
        }

        EventType invoke(Pirate& pirate) override {
            std::cout << "Missionary" << std::endl;
            return m_type;
        }


    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // MISSIONARY_H_