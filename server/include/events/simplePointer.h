#ifndef SIMPLE_POINTER_H_
#define SIMPLE_POINTER_H_

#include "settings.h"
#include "event.h"

namespace jackal {

    class SimplePointer : public Event {
    public:
        explicit SimplePointer(Settings& settings);

        EventType invoke(Pirate& pirate) override;


    private:
        EventType m_type = EventType::NEW_EVENT;
        int m_dcol;
        int m_drow;
    };

} // namespace jackal

#endif // SIMPLE_POINTER_H_