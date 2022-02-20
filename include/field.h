#ifndef FIELD_H_
#define FIELD_H_

#include "event.h"
#include <vector>
#include <memory>

namespace jackal {

    class Field {
    public:
        void generate_field();

        Event &get_element() const noexcept;

    private:
        std::vector<std::vector<std::shared_ptr<Event>>> m_field;
        int m_rows = 11;
        int m_columns = 11;
    };

} // namespace jackal

#endif // FIELD_H_
