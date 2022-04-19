#ifndef SPINNER_H_
#define SPINNER_H_

#include "event.h"

namespace jackal {

    class Spinner : public Event {
    public:
        explicit Spinner(int n);

        EventType invoke(Pirate& pirate) override;


    private:
        int m_cnt;
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // SPINNER_H_