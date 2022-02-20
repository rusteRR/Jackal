#ifndef SPINNER_H_
#define SPINNER_H_

namespace jackal {

    class Spinner : public Event {
    public:
        void invoke(Pirate &pirate) override;

    private:
        int cnt;
    };

} // namespace jackal

#endif // SPINNER_H_