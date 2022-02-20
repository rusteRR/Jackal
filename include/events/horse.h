#ifndef HORSE_H_
#define HORSE_H_

namespace jackal {

    class Horse : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

} // namespace jackal

#endif // HORSE_H_