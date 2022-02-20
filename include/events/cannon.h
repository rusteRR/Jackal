#ifndef CANNON_H_
#define CANNON_H_

namespace jackal {

    class Cannon : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

} // namespace jackal

#endif // CANNON_H_