#ifndef MULTI_POINTER_H_
#define MULTI_POINTER_H_

#include "event.h"

namespace jackal {

    class MultiPointer : public Event {
    public:
        MultiPointer(Settings& settings);

        EventType invoke(Pirate& pirate) override;


    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // MULTI_POINTER_H_