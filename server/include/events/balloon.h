#ifndef BALLOON_H_
#define BALLOON_H_

#include "event.h"

namespace jackal {

    class Ballon : public Event {
    public:
        Ballon();

        EventType invoke(Pirate& pirate) override;

    private:
        EventType m_type = EventType::NEW_EVENT;
    };

} // namespace jackal

#endif // BALLOON_H_