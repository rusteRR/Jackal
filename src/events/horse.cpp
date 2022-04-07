#include "horse.h"

namespace jackal {

    EventType Horse::invoke(Pirate& pirate) {
        std::cout << "Horse" << std::endl;
        std::pair<int, int> response = get_response();
        while (!check_correctness(response.first, response.second)) {
            response = get_response();
        }
        pirate.move(response.first, response.second);
        pirate.set_last_move(eventType::HORSE, response.first, response.second);
        return m_type;
    }

    std::pair<int, int> Horse::get_response() {
        int col, row;
        std::cin >> col >> row;
        return {col, row};
    }


    bool Horse::check_correctness(int col, int row) {
        return true;
    }
}