#ifndef OGRE_H_
#define OGRE_H_

#include "event.h"

namespace jackal {

    class Ogre : public Event {
    public:
        Ogre() : filename("ogre.png") {
        }

        EventType invoke(Pirate& pirate) override;

        std::string get_filename() {
            return filename;
        }

    private:
        EventType m_type = EventType::SIMPLE;
        std::string filename;
    };

} // namespace jackal

#endif // OGRE_H_