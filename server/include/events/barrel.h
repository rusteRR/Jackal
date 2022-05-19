#ifndef BARREL_H_
#define BARREL_H_

#include "event.h"

namespace jackal {

    class Barrel : public Event {
    public:
        Barrel();

        EventType invoke(Pirate& pirate) override;


    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // BARREL_H_