#ifndef KERNELS_H_
#define KERNELS_H_

#include "event.h"

namespace jackal {

    class Kernels : public Event {
    public:
        void invoke(Pirate &pirate) override {
            std::cout << "Kernels" << std::endl;
        }
    };

} // namespace jackal

#endif // KERNELS_H_