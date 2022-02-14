#ifndef PIRATE_H_
#define PIRATE_H_

namespace jackal {
    enum class status { DEAD, ALIVE, DROWN, STUCK, CARRYING_COIN };

    class Pirate {
    public:
        int get_row() const noexcept;

        int get_col() const noexcept;

        int get_coins() const noexcept;

        void set_row() noexcept;

        void set_col() noexcept;

        void set_coins() noexcept;

        void set_status() const noexcept;

        void make_move();

        void go_to_ship() noexcept;

    private:
        status m_status;
        int m_row_pos;
        int m_col_pos;
        int m_coins = 0;
        int m_stucked_for = 0;
    };
}

#endif // PIRATE_H_
