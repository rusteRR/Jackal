#ifndef HORSE_H_
#define HORSE_H_

#include "event.h"

namespace jackal {

    class Horse : public Event {
    public:
        Horse() : filename("horse.png") {
        }

        EventType invoke(Pirate& pirate) override;

        std::string get_filename() {
            return filename;
        }

    private:
        std::string filename;
        EventType m_type = EventType::NEW_EVENT;

        std::pair<int, int> get_response();

        bool check_correctness(int col, int row);
    };

} // namespace jackal

#endif // HORSE_H_