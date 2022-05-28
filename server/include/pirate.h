#ifndef PIRATE_H_
#define PIRATE_H_

#include "fwd.h"
#include "ship.h"
#include "settings.h"
#include <utility>

namespace jackal {

    enum class status { DEAD, ALIVE, DROWN, STUCK, CARRYING_COIN, PROTECTED, ON_BOARD, JUNGLE, DRUNK };
    enum class eventType {PLANE, HORSE, MULTIPOINTER, SIMPLE};
    enum class moveType { SHIP_MOVE, PLAIN };

    class Pirate {
    public:
        Pirate(int col, int row, Ship* ship, Player* m_owner);
        [[nodiscard]] Coords get_coords() const;
        void set_last_move(eventType type, Coords coords);
        status get_status() const;
        std::pair<eventType, Coords> get_last_move() const;
        void set_status(status cur_status);
        void die();
        void stuck(int steps);
        void move(Coords coords, moveType type = moveType::PLAIN);
        void take_coin(int n);
        int drop_coin();
        void drunk(int n);
        int get_coins_amount() const;
        void decrease_debuff();
        void attack_pirate(Game& game);
        void pick_up_rum(int n);
        Coords get_ship_coords() const;
        void drown();
        bool try_to_escape();
        void heal_dead_pirates(Coords spawn_coords);

    private:
        status m_status;
        Ship* m_ship;
        Coords m_coords;
        int m_coins;
        int m_stucked_for = 0;
        int m_drunk_for = 0;
        Player* m_owner;
        std::pair<eventType, Coords> m_last_move;

        void go_to_ship();
    };

}

#endif // PIRATE_H_
