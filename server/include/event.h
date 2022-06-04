#ifndef EVENT_H_
#define EVENT_H_

#include "pirate.h"
#include <iostream>
#include <string>
#include <random>

namespace jackal {

    enum class EventType {SIMPLE, NEW_EVENT};

    class Event {
    public:
        explicit Event(const std::string& file, bool is_av);
        virtual EventType invoke(Pirate& pirate) = 0;
        std::string get_filename();
        bool take_coin(Pirate& pirate, int coins_to_take);
        [[nodiscard]] bool opened_status() const;
        [[nodiscard]] bool is_available_with_coin() const;
        [[nodiscard]] int get_coins_amount() const;
        void increase_coins(int n);
        virtual ~Event() = default;

    protected:
        std::string m_filename;
        int m_coins;
        bool m_is_available_with_coin;
        bool has_treasure;
        bool is_opened;
        std::mersenne_twister_engine<uint_fast32_t, 32,624,397,31,0x9908b0df,11,0xffffffff,7,0x9d2c5680,15,0xefc60000,18,1812433253> eng1;
    };
    
}
#endif // EVENT_H_
