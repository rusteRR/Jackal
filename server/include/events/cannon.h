#ifndef CANNON_H_
#define CANNON_H_

#include "event.h"

namespace jackal {

    class Cannon : public Event {
    public:
        Cannon();

        EventType invoke(Pirate& pirate) override;

    private:
        int m_dcol;
        int m_drow;
        EventType m_type = EventType::NEW_EVENT;
    };

} // namespace jackal

#endif // CANNON_H_