#ifndef CROCODILE_H_
#define CROCODILE_H_

#include "event.h"

namespace jackal {

    class Crocodile : public Event {
    public:
        Crocodile();

        EventType invoke(Pirate& pirate) override;


    private:
        EventType m_type = EventType::NEW_EVENT;
    };

} // namespace jackal

#endif // CROCODILE_H_