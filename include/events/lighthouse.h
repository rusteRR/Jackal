#ifndef LIGHTHOUSE_H_
#define LIGHTHOUSE_H_

namespace jackal {

    class Lighthouse : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

} // namespace jackal

#endif // LIGHTHOUSE_H_