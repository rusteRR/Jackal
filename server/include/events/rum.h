#ifndef RUM_H_
#define RUM_H_

#include "event.h"

namespace jackal {

    class Rum : public Event {
    public:
        Rum();

        EventType invoke(Pirate& pirate) override;


    private:
        EventType m_type = EventType::SIMPLE;
        int bottles = 0;
    };

} // namespace jackal

#endif // RUM_H_