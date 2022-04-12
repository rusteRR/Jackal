#ifndef SPINNER_H_
#define SPINNER_H_

#include "event.h"

namespace jackal {

    class Spinner : public Event {
    public:
        explicit Spinner(int n);

        EventType invoke(Pirate& pirate) override;

        std::string get_filename() override {
            return filename;
        }

    private:
        int m_cnt;
        EventType m_type = EventType::SIMPLE;
        std::string filename;
    };

} // namespace jackal

#endif // SPINNER_H_