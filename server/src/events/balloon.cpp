#include "balloon.h"

jackal::EventType jackal::Ballon::invoke(Pirate &pirate) {
   std::cout << "Balloon" << std::endl;
   auto ship_coords = pirate.get_ship_coords();
   pirate.move(ship_coords.first, ship_coords.second);
   return m_type;
}

jackal::Ballon::Ballon() : Event("balloon.png", true) {
}
