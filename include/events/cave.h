#ifndef CAVE_H_
#define CAVE_H_

namespace jackal {

    class Cave : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

} // namespace jackal

#endif // CAVE_H_