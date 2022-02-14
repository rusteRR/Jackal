#ifndef SHIP_H_
#define SHIP_H_

namespace jackal {

    class Ship {
    public:
        int get_row_pos() const noexcept;

        int get_col_pos() const noexcept;

        int set_row_pos() noexcept;

        int set_col_pos() noexcept;

    private:
        int row_pos;
        int col_pos;
    };

}
#endif //SHIP_H_
