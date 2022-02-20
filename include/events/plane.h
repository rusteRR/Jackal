#ifndef PLANE_H_
#define PLANE_H_

namespace jackal {

    class Plane : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

} // namespace jackal

#endif // PLANE_H_