#ifndef RUM_H_
#define RUM_H_

namespace jackal {

    class Rum : public Event {
    public:
        void invoke(Pirate &pirate) override;

    private:
        int count;
    };

} // namespace jackal

#endif // RUM_H_