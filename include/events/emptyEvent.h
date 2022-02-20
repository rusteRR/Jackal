#ifndef EMPTY_EVENT_H_
#define EMPTY_EVENT_H_

namespace jackal {

} // namespace jackal

class EmptyEvent : public Event {
public:
    void invoke(Pirate &pirate) override {

    }
};


#endif // EMPTY_EVENT_H_