#ifndef PLAYER_H_
#define PLAYER_H_

#include "pirate.h"
#include "ship.h"
#include <vector>
namespace jackal {

    class Player {
    public:
        
    private:
        std::vector<Pirate*> m_pirates;
        int m_total_coins;
        Ship m_ship;
    };

} // namespace jackal

#endif // PLAYER_H_
