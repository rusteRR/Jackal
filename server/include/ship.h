#ifndef SHIP_H_
#define SHIP_H_

#include "pirate.h"
#include "settings.h"
#include <utility>
#include <vector>
#include <memory>

namespace jackal {

    class Ship {
    public:
        Ship(int col, int row);
        Coords get_coords() const;
        bool move(Coords coords);
        void add_pirate(Pirate* pirate);
        void leave_ship(Pirate* pirate);

    private:
        std::vector<Pirate*> pirates_on_board;
        Coords m_coords;

        bool check_move_correctness(Coords coords) const;
    };

}
#endif // SHIP_H_
