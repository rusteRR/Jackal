#ifndef FORTRESS_H_
#define FORTRESS_H_

#include "event.h"

namespace jackal {

    class Fortress : public Event {
    public:
        Fortress() : filename("fortress.png") {
        }

        EventType invoke(Pirate& pirate) override;

        std::string get_filename() override {
            return filename;
        }

    private:
        std::string filename;
        EventType m_type = EventType::SIMPLE;
    };

} // namespace jackal

#endif // FORTRESS_H_