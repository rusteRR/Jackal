#ifndef TREASURE_H_
#define TREASURE_H_

#include "event.h"

namespace jackal {

    class Treasure : public Event {
    public:
        Treasure();

        EventType invoke(Pirate& pirate) override;


    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // TREASURE_H_