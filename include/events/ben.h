#ifndef BEN_H_
#define BEN_H_

namespace jackal {

    class Ben : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

} // namespace jackal

#endif // BEN_H_