#ifndef JUNGLE_H_
#define JUNGLE_H_

namespace jackal {

    class Jungle : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

} // namespace jackal

#endif // JUNGLE_H_