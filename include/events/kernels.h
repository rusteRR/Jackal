#ifndef KERNELS_H_
#define KERNELS_H_

#include "event.h"

namespace jackal {

    class Kernels : public Event {
    public:
        EventType invoke(Pirate& pirate) override {
            std::cout << "Kernels" << std::endl;
            return m_type;
        }

    private:
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // KERNELS_H_