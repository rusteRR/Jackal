#ifndef MISSIONARY_H_
#define MISSIONARY_H_

namespace jackal {

    class Missionary : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

} // namespace jackal

#endif // MISSIONARY_H_