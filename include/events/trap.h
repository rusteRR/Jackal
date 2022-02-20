#ifndef TRAP_H_
#define TRAP_H_

namespace jackal {

    class Trap : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

} // namespace jackal

#endif // TRAP_H_