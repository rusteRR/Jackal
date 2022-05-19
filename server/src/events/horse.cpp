#include "horse.h"

jackal::EventType jackal::Horse::invoke(Pirate& pirate) {
    std::cout << "Horse" << std::endl;
    is_opened = true;
    pirate.set_last_move(eventType::HORSE, pirate.get_coords());
    /*Coords response = get_response();
    while (!check_correctness(response)) {
        response = get_response();
    }*/
    //pirate.move(response);
    return EventType::SIMPLE;
}

jackal::Coords jackal::Horse::get_response() {
    int col, row;
    std::cin >> col >> row;
    return {col, row};
}


bool jackal::Horse::check_correctness(Coords coords) {
    return true;
}