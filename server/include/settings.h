#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <vector>
#include <chrono>

namespace jackal {

    const std::vector<std::pair<int, int>> direct_directions = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
    };

    const std::vector<std::pair<int, int>> diagonal_directions = {
            {1, 1},
            {-1, -1},
            {1, -1},
            {-1, 1}
    };

    const int COORD_LOWER_BOUND = 0;
    const int COORD_UPPER_BOUND = 12;

    enum class SimplePointerType {DIRECT, DIAGONAL};

    enum class MultiPointerType {DOUBLE_DIRECT, DOUBLE_DIAGONAL, TRIPLE, QUAD_DIRECT, QUAD_DIAGONAL};

    struct Coords {
        int x;
        int y;

        bool operator==(const Coords& rhs) const;
        bool operator!=(const Coords& rhs) const;
    };

    class Settings {
    public:
        Settings() = default;
        SimplePointerType get_simple_pointer();
        MultiPointerType get_multi_pointer();
        static std::pair<int, int> get_direct_directions();
        static std::pair<int, int>  get_diagonal_directions();

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
