#include "../include/field.h"

namespace jackal {
    void Field::generate_field() {
        std::map<std::string, std::function<std::shared_ptr<Event>()>> event_factory{
                {"empty",          []() { return std::make_shared<EmptyEvent>(); }},
                {"simple-pointer", []() { return std::make_shared<SimplePointer>(); }},
                {"multi-pointer",  []() { return std::make_shared<MultiPointer>(); }},
                {"horse",          []() { return std::make_shared<Horse>(); }},
                {"spinner-2",      []() { return std::make_shared<Spinner>(); }},
                {"spinner-3",      []() { return std::make_shared<Spinner>(); }},
                {"spinner-4",      []() { return std::make_shared<Spinner>(); }},
                {"spinner-5",      []() { return std::make_shared<Spinner>(); }},
                {"ice",            []() { return std::make_shared<Ice>(); }},
                {"trap",           []() { return std::make_shared<Trap>(); }},
                {"crocodile",      []() { return std::make_shared<Crocodile>(); }},
                {"ogre",           []() { return std::make_shared<Ogre>(); }},
                {"fortress",       []() { return std::make_shared<Fortress>(); }},
                {"fortress-heal",  []() { return std::make_shared<Fortress>(); }},
                {"treasure",       []() { return std::make_shared<Treasure>(); }},
                {"coins-1",        []() { return std::make_shared<Coins>(); }},
                {"coins-2",        []() { return std::make_shared<Coins>(); }},
                {"coins-3",        []() { return std::make_shared<Coins>(); }},
                {"coins-4",        []() { return std::make_shared<Coins>(); }},
                {"coins-5",        []() { return std::make_shared<Coins>(); }},
                {"plane",          []() { return std::make_shared<Plane>(); }},
                {"balloon",        []() { return std::make_shared<Ballon>(); }},
                {"cannon",         []() { return std::make_shared<Cannon>(); }},
                {"lighthouse",     []() { return std::make_shared<Lighthouse>(); }},
                {"ben",            []() { return std::make_shared<Ben>(); }},
                {"missionary",     []() { return std::make_shared<Missionary>(); }},
                {"friday",         []() { return std::make_shared<Friday>(); }},
                {"rum-1",          []() { return std::make_shared<Rum>(); }},
                {"rum-2",          []() { return std::make_shared<Rum>(); }},
                {"rum-3",          []() { return std::make_shared<Rum>(); }},
                {"barrel",         []() { return std::make_shared<Barrel>(); }},
                {"cave",           []() { return std::make_shared<Cave>(); }},
                {"earthquake",     []() { return std::make_shared<Earthquake>(); }},
                {"jungle",         []() { return std::make_shared<Jungle>(); }},
                {"grass",          []() { return std::make_shared<Grass>(); }},
                {"boat",           []() { return std::make_shared<Boat>(); }},
                {"kernels",        []() { return std::make_shared<Kernels>(); }},
                {"cart",           []() { return std::make_shared<Cart>(); }}
        };
        std::ifstream f("../data/events.txt");
        std::string event_name;
        int event_count;
        std::vector<std::pair<int, int>> random_coords(m_rows * m_columns);
        for (int i = 0; i < m_rows; ++ i) {
            for (int j = 0; j < m_columns; ++ j) {
                random_coords[i * m_columns + j] = {i, j};
            }
        }
        std::shuffle(random_coords.begin(), random_coords.end(), std::mt19937(std::random_device()()));
        m_field.resize(m_rows, std::vector<std::shared_ptr<Event>>(m_columns));
        int coord_ind = 0;
        while (f >> event_name >> event_count) {
            for (int i = 0; i < event_count; ++ i) {
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] = event_factory[event_name]();
                coord_ind ++;
            }
        }
    }
}
