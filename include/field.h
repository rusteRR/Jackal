#ifndef FIELD_H_
#define FIELD_H_

#include "event.h"
#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>

namespace jackal {

    class Field {
    public:
        void generate_field();

        Event& get_element() const noexcept;

    private:
        std::vector<std::vector<std::unique_ptr<Event>>> m_field;
        int m_rows = 11;
        int m_columns = 11;
};

} // namespace jackal

#endif // FIELD_H_
