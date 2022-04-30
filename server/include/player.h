#ifndef PLAYER_H_
#define PLAYER_H_

#include "pirate.h"
#include "ship.h"
#include <vector>
#include <memory>

namespace jackal {

    class Player {
    public:
        Player(int total_pirates, int col, int row);
        std::shared_ptr<Pirate> get_pirate(int pirate_id);
        [[nodiscard]] std::vector<std::shared_ptr<Pirate>> get_all_pirates() const;
        void get_rum_bottles(int n);
        void move_ship(int col, int row);
        void increase_coins(int n);
        
    private:
        std::vector<std::shared_ptr<Pirate>> m_pirates;
        int m_total_coins;
        int m_rum_bottles;
        Ship m_ship;
    };

} // namespace jackal

#endif // PLAYER_H_
