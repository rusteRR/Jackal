#ifndef PLANE_H_
#define PLANE_H_

#include "event.h"

namespace jackal {

    class Plane : public Event {
    public:
        Plane();

        EventType invoke(Pirate& pirate) override;

        static bool check_move_correctness(Coords new_coords);


    private:
        EventType m_type = EventType::NEW_EVENT;
    };

} // namespace jackal

#endif // PLANE_H_