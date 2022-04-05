#ifndef PIRATE_H_
#define PIRATE_H_

#include <QLabel>
#include "fwd.h"
#include "ship.h"
#include <utility>

namespace jackal {
    enum class status { DEAD, ALIVE, DROWN, STUCK, CARRYING_COIN, PROTECTED};
    enum class eventType {PLANE, HORSE, MULTIPOINTER, SIMPLE};

    class Pirate : public QObject {
    Q_OBJECT
    public:
        Pirate(int col, int row, Ship* ship);

        [[nodiscard]] std::pair<int, int> get_coords() const;

        void ice();

        void set_last_move(eventType type, int col, int row);

        status get_status() const;

        void set_status(status cur_status);

        void die();

        void stuck(int steps);

        void move(int d_col, int d_row);

        void attack_pirate(Game& game);

    private:
        status m_status;
        Ship* m_ship;
        int m_row;
        int m_col;
        int m_stucked_for = 0;
        std::pair<eventType, std::pair<int, int>> m_last_move;

        void go_to_ship();
    };

}

#endif // PIRATE_H_
