#ifndef SHIP_H_
#define SHIP_H_

#include <utility>

namespace jackal {

    class Ship {
    public:
        Ship(int col, int row);

        std::pair<int, int> get_coords();


    private:
        int m_col;
        int m_row;
    };

}
#endif // SHIP_H_
