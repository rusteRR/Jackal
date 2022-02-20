#ifndef CROCODILE_H_
#define CROCODILE_H_

namespace jackal {

    class Crocodile : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

} // namespace jackal

#endif // CROCODILE_H_