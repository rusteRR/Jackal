#ifndef SHIP_H_
#define SHIP_H_

#include "pirate.h"
#include <utility>
#include <vector>
#include <memory>

namespace jackal {

    class Ship {
    public:
        Ship(int col, int row);
        std::pair<int, int> get_coords();
        void move(int col, int row);
        void add_pirate(const std::shared_ptr<Pirate>& pirate);
        void leave_ship(Pirate* pirate);

    private:
        std::vector<std::shared_ptr<Pirate>> pirates_on_board;
        int m_col;
        int m_row;

        bool check_move_correctness(int col, int row) const;
    };

}
#endif // SHIP_H_
