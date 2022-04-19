#ifndef MULTI_POINTER_H_
#define MULTI_POINTER_H_

#include "event.h"

namespace jackal {

    class MultiPointer : public Event {
    public:
        MultiPointer() : Event("multiPointer.png", true) {
        }

        EventType invoke(Pirate& pirate) override {
            std::cout << "MultiPointer" << std::endl;
            return m_type;
        }


    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // MULTI_POINTER_H_