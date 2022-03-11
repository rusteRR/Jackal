#ifndef BEN_H_
#define BEN_H_

#include "event.h"

namespace jackal {

    class Ben : public Event {
    public:
        EventType invoke(Pirate& pirate) override {
            std::cout << "Ben" << std::endl;
            return m_type;
        }

    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // BEN_H_