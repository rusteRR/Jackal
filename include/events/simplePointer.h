#ifndef SIMPLE_POINTER_H_
#define SIMPLE_POINTER_H_

#include "event.h"

namespace jackal {

    class SimplePointer : public Event {
    public:
        void invoke(Pirate &pirate) override;

    private:
        int m_direction;
    };

} // namespace jackal

#endif // SIMPLE_POINTER_H_