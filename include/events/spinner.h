#ifndef SPINNER_H_
#define SPINNER_H_

#include "event.h"

namespace jackal {

    class Spinner : public Event {
    public:
        EventType invoke(Pirate &pirate) override {
            std::cout << "Spinner" << std::endl;
        };

    private:
        int cnt;
    };

} // namespace jackal

#endif // SPINNER_H_