#ifndef FRIDAY_H_
#define FRIDAY_H_

namespace jackal {

    class Friday : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

} // namespace jackal

#endif // FRIDAY_H_