#ifndef PIRATE_H_
#define PIRATE_H_

namespace jackal {
    enum class status { DEAD, ALIVE, DROWN, STUCK, BRINGING_COIN };

    class pirate {
    public:
        int get_row() const noexcept;

        int get_col() const noexcept;

        int set_row() const noexcept;

        int set_col() const noexcept;

    private:
        status m_status;
        int x_pos;
        int y_pos;
    };
}

#endif // PIRATE_H_
