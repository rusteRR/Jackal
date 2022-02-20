#ifndef COINS_H_
#define COINS_H_

namespace jackal {

    class Coins : public Event {
    public:
        void invoke(Pirate &pirate) override;

    private:
        int amount;
    };

} // namespace jackal

#endif // COINS_H_