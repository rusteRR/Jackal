#ifndef PLAYER_H_
#define PLAYER_H_

#include "pirate.h"
#include "ship.h"
#include <vector>
#include <optional>
#include <iostream>

namespace jackal {

    class Player {
    public:
        Player(int total_pirates, int col_, int row_) : m_total_coins(0) {
            for (int i = 0; i < total_pirates; i++) {
                m_pirates.emplace_back(col_, row_);
            }
        }

        Pirate* get_pirate(int col, int row);

        void print_pirates() {
            for (auto elem : m_pirates) {
                std::cout << elem.get_coords().first << " " << elem.get_coords().second << std::endl;
            }
        }
        
    private:
        std::vector<Pirate> m_pirates;
        int m_total_coins;
        Ship m_ship;
    };

} // namespace jackal

#endif // PLAYER_H_
