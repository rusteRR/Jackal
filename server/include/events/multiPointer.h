#ifndef MULTI_POINTER_H_
#define MULTI_POINTER_H_

#include "event.h"
#include <set>

namespace jackal {

    class MultiPointer : public Event {
    public:
        MultiPointer(Settings& settings);

        EventType invoke(Pirate& pirate) override;


    private:
        EventType m_type = EventType::SIMPLE;
        std::set<std::pair<int, int>> directions;
    };

} // namespace jackal

#endif // MULTI_POINTER_H_