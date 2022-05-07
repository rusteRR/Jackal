#ifndef EVENT_H_
#define EVENT_H_

#include "pirate.h"
#include <iostream>
#include <string>

namespace jackal {

    enum class EventType {SIMPLE, NEW_EVENT};

    class Event {
    public:
        explicit Event(const std::string& file, bool is_av);
        virtual EventType invoke(Pirate& pirate) = 0;
        std::string get_filename();
        bool take_coin(Pirate& pirate);
        [[nodiscard]] bool opened_status() const;
        [[nodiscard]] bool is_available_with_coin() const;
        [[nodiscard]] int get_coins_amount() const;
        void increase_coins(int n);
        virtual ~Event() = default;

    protected:
        std::string m_filename;
        int m_coins;
        bool m_is_available_with_coin;
        bool is_opened;
    };
    
}
#endif // EVENT_H_
