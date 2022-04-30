#ifndef FIELD_H_
#define FIELD_H_

#include "event.h"
#include "settings.h"
#include <vector>
#include <memory>

namespace jackal {

    class Field {
    public:
        void generate_field(Settings& settings);
        [[nodiscard]] Event& get_element(int col, int row) const;

    private:
        std::vector<std::vector<std::shared_ptr<Event>>> m_field;
        int m_rows = 13;
        int m_columns = 13;
    };

} // namespace jackal

#endif // FIELD_H_
