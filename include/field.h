#ifndef FIELD_H_
#define FIELD_H_

#include "event.h"
#include <vector>

namespace jackal {

    class Field {
    public:
        void generate_field();

        Event& get_element() const noexcept;

    private:
        std::vector<std::vector<Event>> m_field;
};

} // namespace jackal

#endif // FIELD_H_
