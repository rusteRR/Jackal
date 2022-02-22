#ifndef MULTI_POINTER_H_
#define MULTI_POINTER_H_

#include "event.h"

namespace jackal {

    class MultiPointer : public Event {
    public:
        void invoke(Pirate &pirate) override {
            std::cout << "MultiPointer" << std::endl;
        }
    };

} // namespace jackal

#endif // MULTI_POINTER_H_