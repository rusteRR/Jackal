#ifndef EVENT_H_
#define EVENT_H_

#include "pirate.h"

namespace jackal {

    class Event {
    public:
        virtual void invoke(Pirate& pirate) = 0;
        virtual ~Event() = 0;
    };
    
    class EmptyEvent : public Event{
    public:
        void invoke(Pirate& pirate) override;
    };
    
    class SimplePointer : public Event {
    public:
        SimplePointer(int drow, int dcol);

        void invoke(Pirate &pirate) override;

    private:
        int m_drow;
        int m_dcol;

    };

    class MultiPointer : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

    class Spinner : public Event {
    public:
        void invoke(Pirate &pirate) override;

    private:
        int cnt;
    };

    class Horse : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

    class Ice : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

    class Trap : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };
    
    class Crocodile : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

    class Ogre : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

    class Fortress : public Event {
    public:
        void invoke(Pirate &pirate) override;

    private:
        bool heal;
    };

    class Treasure : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

    class Coins : public Event {
    public:
        void invoke(Pirate &pirate) override;

    private:
        const int amount;
    };

    class Plane : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

    class Ballon : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

    class Cannon : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

    class Lighthouse : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

    class Ben : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

    class Missionary : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

    class Friday : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

    class Rum : public Event {
    public:
        void invoke(Pirate &pirate) override;

    private:
        int count;
    };

    class Barrel : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

    class Cave : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

    class Earthquake : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

    class Jungle : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

    class Grass : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

    class Boat : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

    class Kernels : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

    class Cart : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };
}
#endif // EVENT_H_
