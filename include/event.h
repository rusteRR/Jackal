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
        void invoke(Pirate& pirate) override{
            return;
        }
    };
    
    class SimplePointer : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }
    private:
        int m_direction;
    };

    class MultiPointer : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }
    }

    class Horse : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }
    }

    class Spinner : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }

    private:
        int cnt;
    }

    class Horse : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }
    }

    class Ice : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }
    }

    class Trap : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }
    }
    
    class Crocodile : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }
    }

    class Ogre : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }
    }

    class Fortress : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }

    private:
        bool heal;
    }

    class Treasure : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }
    }

    class Coins : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }
        const int amount;
    }

    class Plane : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }
    }

    class Ballon : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }
    }

    class Cannon : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }
    }

    class Lighthouse : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }
    }

    class Ben : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }
    }

    class Missionary : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }
    }

    class Friday : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }
    }

    class Rum : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }

    private:
        int count;
    }

    class Barrel : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }
    }

    class Cave : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }
    }

    class Earthquake : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }
    }

    class Jungle : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }
    }

    class Grass : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }
    }

    class Boat : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }
    }

    class Kernels : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }
    }

    class Cart : public Event {
    public:
        void invoke(Pirate &pirate) override {
            //TODO
            return;
        }
    }
    
    class MoveEvent : public Event {
    public:
        void move(Pirate& pirate) override;
    };
}
#endif // EVENT_H_
