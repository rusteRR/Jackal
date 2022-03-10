#ifndef PIRATE_H_
#define PIRATE_H_

#include <utility>
#include "fwd.h"

namespace jackal {
    enum class status { DEAD, ALIVE, DROWN, STUCK, CARRYING_COIN };

    class Pirate {
    public:
        Pirate(int col_, int row_) : m_col(col_), m_row(row_), m_status(status::ALIVE) {
        }

        [[nodiscard]] std::pair<int, int> get_coords() const;

        int get_coins() const;

        void set_status(status new_status);

        void move(int d_col, int d_row);

        void attack_pirate(Game& game);

        void go_to_ship();

    private:
        status m_status;
        int m_row;
        int m_col;
        int m_coins = 0;
        int m_stucked_for = 0;
    };
}

#endif // PIRATE_H_
