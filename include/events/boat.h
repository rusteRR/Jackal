#ifndef BOAT_H_
#define BOAT_H_

namespace jackal {

    class Boat : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

} // namespace jackal

#endif // BOAT_H_