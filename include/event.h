#ifndef EVENT_H_
#define EVENT_H_

#include "pirate.h"

namespace jackal {

    class Event {
    public:
        virtual void invoke(Pirate &pirate) = 0;

        virtual ~Event() = 0;
    };

    class EmptyEvent : public Event {
    public:
        void invoke(Pirate &pirate) override {

        }
    };

    class SimplePointer : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }

    private:
        int m_direction;
    };

    class MultiPointer : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }
    };

    class Horse : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }
    };

    class Spinner : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }

    private:
        int cnt;
    };

    class Ice : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }
    };

    class Trap : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }
    };

    class Crocodile : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }
    };

    class Ogre : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }
    };

    class Fortress : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }

    private:
        bool heal;
    };

    class Treasure : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }
    };

    class Coins : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }

    private:
        int amount;
    };

    class Plane : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }
    };

    class Ballon : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }
    };

    class Cannon : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }
    };

    class Lighthouse : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }
    };

    class Ben : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }
    };

    class Missionary : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }
    };

    class Friday : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }
    };

    class Rum : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }

    private:
        int count;
    };

    class Barrel : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }
    };

    class Cave : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }
    };

    class Earthquake : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }
    };

    class Jungle : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }
    };

    class Grass : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }
    };

    class Boat : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }
    };

    class Kernels : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }
    };

    class Cart : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO

        }
    };
    
}
#endif // EVENT_H_
