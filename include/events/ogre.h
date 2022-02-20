#ifndef OGRE_H_
#define OGRE_H_

namespace jackal {

    class Ogre : public Event {
    public:
        void invoke(Pirate &pirate) override;
    };

} // namespace jackal

#endif // OGRE_H_