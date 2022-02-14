#ifndef PIRATE_H_
#define PIRATE_H_

namespace jackal {
    enum class status { DEAD, ALIVE, DROWN, STUCK, BRINGING_COIN };

    class pirate {
    public:
        int get_x_pos() const noexcept;

        int get_y_pos() const noexcept;

    private:
        status m_status;
        int x_pos;
        int y_pos;
    };
}

#endif // PIRATE_H_