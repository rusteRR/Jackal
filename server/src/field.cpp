#include "field.h"
#include "allEvents.h"
#include <algorithm>
#include <fstream>
#include <random>
#include <map>
#include <chrono>
#include <functional>

namespace water_cells_execept_borders {
    constexpr int TOTAL_CELLS = 4;
    constexpr int x[] = {1, 1, 11, 11};
    constexpr int y[] = {1, 11, 1, 11};
}

namespace jackal {
    void Field::generate_field(Settings& settings) {
        std::map<std::string, std::function<std::shared_ptr<Event>()>> event_factory {
                {"empty",          []() { return std::make_shared<EmptyEvent>(); }},
                {"simple-pointer", [&]() { return std::make_shared<SimplePointer>(settings); }},
                {"multi-pointer",  [&]() { return std::make_shared<MultiPointer>(settings); }},
                {"horse",          []() { return std::make_shared<Horse>(); }},
                {"spinner-2",      []() { return std::make_shared<Spinner>(2); }},
                {"spinner-3",      []() { return std::make_shared<Spinner>(3); }},
                {"spinner-4",      []() { return std::make_shared<Spinner>(4); }},
                {"spinner-5",      []() { return std::make_shared<Spinner>(5); }},
                {"ice",            []() { return std::make_shared<Ice>(); }},
                {"trap",           []() { return std::make_shared<Trap>(); }},
                {"crocodile",      []() { return std::make_shared<Crocodile>(); }},
                {"ogre",           []() { return std::make_shared<Ogre>(); }},
                {"fortress",       []() { return std::make_shared<Fortress>(); }},
                {"fortress-heal",  []() { return std::make_shared<Healer>(); }},
                {"treasure",       []() { return std::make_shared<Treasure>(); }},
                {"coins-1",        []() { return std::make_shared<Coins>(1); }},
                {"coins-2",        []() { return std::make_shared<Coins>(2); }},
                {"coins-3",        []() { return std::make_shared<Coins>(3); }},
                {"coins-4",        []() { return std::make_shared<Coins>(4); }},
                {"coins-5",        []() { return std::make_shared<Coins>(5); }},
                {"plane",          []() { return std::make_shared<Plane>(); }},
                {"balloon",        []() { return std::make_shared<Ballon>(); }},
                {"cannon",         []() { return std::make_shared<Cannon>(); }},
                {"lighthouse",     []() { return std::make_shared<Lighthouse>(); }},
                {"rum-1",          []() { return std::make_shared<Rum>(1); }},
                {"rum-2",          []() { return std::make_shared<Rum>(2); }},
                {"rum-3",          []() { return std::make_shared<Rum>(3); }},
                {"barrel",         []() { return std::make_shared<Barrel>(); }},
                {"cave",           []() { return std::make_shared<Cave>(); }},
                {"earthquake",     []() { return std::make_shared<Earthquake>(); }},
                {"jungle",         []() { return std::make_shared<Jungle>(); }},
                {"grass",          []() { return std::make_shared<Grass>(); }},
        };

        std::ifstream f("events.txt");
        std::string event_name;
        int event_count;
        int rows_no_water = m_rows - 2;
        int columns_no_water = m_columns - 2;
        std::vector<std::pair<int, int>> random_coords;
        for (int i = 0; i < rows_no_water; ++i) {
            for (int j = 0; j < columns_no_water; ++j) {
                if (i % 10 == 0 && j % 10 == 0) continue;
                random_coords.emplace_back(i + 1, j + 1);
            }
        }
        //std::mt19937 gen{std::random_device()()};
        std::shuffle(random_coords.begin(), random_coords.end(), std::mt19937(std::mersenne_twister_engine<uint_fast32_t, 32,624,397,31,0x9908b0df,11,0xffffffff,7,0x9d2c5680,15,0xefc60000,18,1812433253>((uint32_t)std::chrono::steady_clock::now().time_since_epoch().count())));
        m_field.resize(m_rows, std::vector<std::shared_ptr<Event>>(m_columns));
        for (int i = 0; i < m_columns; ++i) {
            m_field[0][i] = std::make_shared<Water>();
            m_field[m_rows - 1][i] = std::make_shared<Water>();
        }
        for (int i = 0; i < m_rows; ++i) {
            m_field[i][0] = std::make_shared<Water>();
            m_field[i][m_columns - 1] = std::make_shared<Water>();
        }
        for (int i = 0; i < water_cells_execept_borders::TOTAL_CELLS; i++) {
            int x = water_cells_execept_borders::x[i];
            int y = water_cells_execept_borders::y[i];
            m_field[x][y] = std::make_shared<Water>();
        }
        int coord_ind = 0;
        while (f >> event_name >> event_count) {
            for (int i = 0; i < event_count; ++i) {
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] = event_factory[event_name]();
                coord_ind++;
            }
        }
    }

    Event& Field::get_element(int col, int row) const {
        return *m_field[col][row];
    }
}
