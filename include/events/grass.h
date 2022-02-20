#ifndef GRASS_H_
#define GRASS_H_

namespace jackal {

    class Grass : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

} // namespace jackal

#endif // GRASS_H_