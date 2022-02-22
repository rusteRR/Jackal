#ifndef RUM_H_
#define RUM_H_

#include "event.h"

namespace jackal {

    class Rum : public Event {
    public:
        void invoke(Pirate &pirate) override {
            std::cout << "Rum" << std::endl;
        }

    private:
        int count;
    };

} // namespace jackal

#endif // RUM_H_