#ifndef GAME_H_
#define GAME_H_

#include "field.h"
#include "player.h"
#include <vector>

namespace jackal {
  enum class game_type{};
  class Game {
  public:

  private:
    field m_field;
    std::vector<Player*> players;
    int current_player;
  };

} // namespace jackal

#endif //GAME_H_
