#ifndef BARREL_H_
#define BARREL_H_

namespace jackal {

    class Barrel : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

} // namespace jackal

#endif // BARREL_H_