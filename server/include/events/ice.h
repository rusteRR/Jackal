#ifndef ICE_H_
#define ICE_H_

#include "event.h"

namespace jackal {

    class Ice : public Event {
    public:
        Ice() : filename("ice.png") {
        }

        EventType invoke(Pirate& pirate) override;

        std::string get_filename() override {
            return filename;
        }

    private:
        std::string filename;
        EventType m_type = EventType::NEW_EVENT;
    };

} // namespace jackal

#endif // ICE_H_