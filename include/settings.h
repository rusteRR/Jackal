#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <vector>

namespace jackal {

    enum class SimplePointerType {DIRECT, DIAGONAL};

    enum class MultiPointerType {DOUBLE_DIRECT, DOUBLE_DIAGONAL, TRIPLE, QUAD_DIRECT, QUAD_DIAGONAL};

    class Settings {
    public:
        Settings() = default;

        SimplePointerType get_simple_pointer();

        MultiPointerType get_multi_pointer();

    private:
        std::vector<std::pair<SimplePointerType, int>> m_simple_pointer = {
                {SimplePointerType::DIRECT, 3},
                {SimplePointerType::DIAGONAL, 3}
        };

        std::vector<std::pair<MultiPointerType, int>> m_multi_pointer = {
                {MultiPointerType::DOUBLE_DIAGONAL, 3},
                {MultiPointerType::DOUBLE_DIRECT, 3},
                {MultiPointerType::TRIPLE, 3},
                {MultiPointerType::QUAD_DIRECT, 3},
                {MultiPointerType::QUAD_DIAGONAL, 3}
        };
    };
} // namespace jackal


#endif