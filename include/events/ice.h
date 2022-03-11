#ifndef ICE_H_
#define ICE_H_

#include "event.h"

namespace jackal {

    class Ice : public Event {
    public:
        EventType invoke(Pirate& pirate) override {
            std::cout << "Ice" << std::endl;
            return m_type;
        }

    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // ICE_H_