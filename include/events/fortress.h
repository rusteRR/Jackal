#ifndef FORTRESS_H_
#define FORTRESS_H_

namespace jackal {

    class Fortress : public Event {
    public:
        void invoke(Pirate &pirate) override;

    private:
        bool heal;
    };

} // namespace jackal

#endif // FORTRESS_H_