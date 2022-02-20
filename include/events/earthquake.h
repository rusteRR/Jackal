#ifndef EARTHQUAKE_H_
#define EARTHQUAKE_H_

namespace jackal {

    class Earthquake : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

} // namespace jackal

#endif // EARTHQUAKE_H_