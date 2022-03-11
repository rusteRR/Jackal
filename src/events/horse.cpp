#include "horse.h"

namespace jackal {

    EventType Horse::invoke(Pirate& pirate) {
        std::pair<int, int> response = get_response();
        return m_type;
    }

    std::pair<int, int> Horse::get_response() {
        int col, row;
        std::cin >> col >> row;
        return {col, row};
    }


    /*bool Horse::check_correctness(int col, int row) {
        return true;
    }*/
}