#ifndef PIRATE_H_
#define PIRATE_H_

namespace jackal {
    enum class status { DEAD, ALIVE, DROWN, STUCK, CARRYING_COIN };

    class Pirate {
    public:
        int get_row() const noexcept;

        int get_col() const noexcept;

        int set_row() const noexcept;

        int set_col() const noexcept;

    private:
        status m_status;
        int row_pos;
        int col_pos;
        int m_coins = 0;
        int m_stucked_for = 0;
    };
}

#endif // PIRATE_H_
