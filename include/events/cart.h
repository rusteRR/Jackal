#ifndef CART_H_
#define CART_H_

namespace jackal {

    class Cart : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

} // namespace jackal

#endif // CART_H_