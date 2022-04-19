#ifndef EVENT_H_
#define EVENT_H_

#include "pirate.h"
#include <iostream>
#include <string>

namespace jackal {

    enum class EventType {SIMPLE, NEW_EVENT};

    class Event {
    public:
        explicit Event(const std::string& file);
        virtual EventType invoke(Pirate& pirate) = 0;
        std::string get_filename();
        bool take_coin(Pirate& pirate);
        virtual ~Event() = default;

    protected:
        std::string m_filename;
        int m_coins;
        bool is_opened;
    };
    
}
#endif // EVENT_H_
