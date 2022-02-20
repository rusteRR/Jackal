#ifndef TREASURE_H_
#define TREASURE_H_

namespace jackal {

    class Treasure : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

} // namespace jackal

#endif // TREASURE_H_