#ifndef RUM_H_
#define RUM_H_

#include "event.h"

namespace jackal {

    class Rum : public Event {
    public:
        EventType invoke(Pirate& pirate) override {
            std::cout << "Rum" << std::endl;
            return m_type;
        }

    private:
        EventType m_type = EventType::SIMPLE;
        int count;
    };

} // namespace jackal

#endif // RUM_H_