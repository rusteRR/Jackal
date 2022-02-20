#ifndef ICE_H_
#define ICE_H_

namespace jackal {

    class Ice : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

} // namespace jackal

#endif // ICE_H_