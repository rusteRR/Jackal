#ifndef KERNELS_H_
#define KERNELS_H_

namespace jackal {

    class Kernels : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

} // namespace jackal

#endif // KERNELS_H_