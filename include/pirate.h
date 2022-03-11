#ifndef PIRATE_H_
#define PIRATE_H_

#include "fwd.h"
#include "ship.h"
#include <utility>

namespace jackal {
    enum class status { DEAD, ALIVE, DROWN, STUCK, CARRYING_COIN};

    class Pirate {
    public:
        Pirate(int col, int row, const Ship& ship);

        [[nodiscard]] std::pair<int, int> get_coords() const;

        int get_coins() const;

        void die();

        void stuck(int steps);

        void move(int d_col, int d_row);

        void attack_pirate(Game& game);

    private:
        status m_status;
        Ship m_ship;
        int m_row;
        int m_col;
        int m_coins = 0;
        int m_stucked_for = 0;

        void go_to_ship();
    };
}

#endif // PIRATE_H_
