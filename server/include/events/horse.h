#ifndef HORSE_H_
#define HORSE_H_

#include "event.h"

namespace jackal {

    class Horse : public Event {
    public:
        Horse() : Event("horse.png", true) {
        }

        EventType invoke(Pirate& pirate) override;


    private:
        EventType m_type = EventType::NEW_EVENT;

        Coords get_response();

        bool check_correctness(Coords coords);
    };

} // namespace jackal

#endif // HORSE_H_