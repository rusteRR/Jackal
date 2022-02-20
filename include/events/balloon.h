#ifndef BALLOON_H_
#define BALLOON_H_

namespace jackal {

    class Ballon : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

} // namespace jackal

#endif // BALLOON_H_