#ifndef MULTI_POINTER_H_
#define MULTI_POINTER_H_

namespace jackal {

    class MultiPointer : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

} // namespace jackal

#endif // MULTI_POINTER_H_