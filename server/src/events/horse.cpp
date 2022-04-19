#include "horse.h"

jackal::EventType jackal::Horse::invoke(Pirate& pirate) {
    std::cout << "Horse" << std::endl;
    std::pair<int, int> response = get_response();
    while (!check_correctness(response.first, response.second)) {
        response = get_response();
    }
    pirate.move(response.first, response.second);
    pirate.set_last_move(eventType::HORSE, response.first, response.second);
    return m_type;
}

std::pair<int, int> jackal::Horse::get_response() {
    int col, row;
    std::cin >> col >> row;
    return {col, row};
}


bool jackal::Horse::check_correctness(int col, int row) {
    return true;
}