#include "../include/field.h"
namespace jackal{
    void Field::generate_field() {
        std::ifstream f("../data/events.txt");
        std::string event_name;
        int event_count;
        std::vector<std::pair<int,int>> random_coords(m_rows * m_columns);
        for (int i = 0; i < m_rows; ++i){
            for (int j = 0; j < m_columns; ++j){
                random_coords[i * m_columns + j] = {i, j};
            }
        }
        std::random_shuffle(random_coords.begin(), random_coords.end());
        m_field.resize(m_rows, std::vector<std::unique_ptr<Event>>(m_columns));
        int coord_ind = 0;
        while(f >> event_name >> event_count){
            // copy-paste this 'if' for other 36 cards
            if (f == "empty"){
                for (; event_count > 0; --event_count) {
                    m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                            std::make_unique<EmptyEvent>();
                    coord_ind++;
                }
            } else if (f == "simple-pointer"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<SimplePointer>();
                coord_ind++;
            } else if (f == "multi-pointer"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<MultiPointer>();
                coord_ind++;
            } else if (f == "horse"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Horse>();
                coord_ind++;
            } else if (f == "spinner-2"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Spinner>();// TODO
                coord_ind++;
            } else if (f == "spinner-3"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Spinner>();// TODO
                coord_ind++;
            } else if (f == "spinner-4"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Spinner>(); // TODO
                coord_ind++;
            } else if (f == "spinner-5"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Spinner>(); // TODO
                coord_ind++;
            } else if (f == "ice"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Ice>();
                coord_ind++;
            } else if (f == "trap"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Trap>();
                coord_ind++;
            } else if (f == "crocodile"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Crocodile>();
                coord_ind++;
            } else if (f == "ogre"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Ogre>();
                coord_ind++;
            } else if (f == "fortress"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Fortress>();
                coord_ind++;
            } else if (f == "fortress-heal"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Fortress>(); //TODO
                coord_ind++;
            } else if (f == "treasure"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Treasure>(); // TODO
                coord_ind++;
            } else if (f == "coins-1"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Coins>(); // TODO
                coord_ind++;
            } else if (f == "coins-2"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Coins>(); // TODO
                coord_ind++;
            } else if (f == "coins-3"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Coins>(); // TODO
                coord_ind++;
            } else if (f == "coins-4"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Coins>(); // TODO
                coord_ind++;
            } else if (f == "coins-5"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Coins>(); // TODO
                coord_ind++;
            } else if (f == "plane"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Plane>();
                coord_ind++;
            } else if (f == "balloon"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Balloon>();
                coord_ind++;
            } else if (f == "cannon"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Cannon>();
                coord_ind++;
            } else if (f == "lighthouse"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Lighthouse>();
                coord_ind++;
            } else if (f == "ben"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Ben>();
                coord_ind++;
            } else if (f == "missionary"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Missionary>();
                coord_ind++;
            } else if (f == "friday"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Friday>();
                coord_ind++;
            } else if (f == "rum-1"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Rum>(); // TODO
                coord_ind++;
            } else if (f == "rum-2"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Rum>(); // TODO
                coord_ind++;
            } else if (f == "rum-3"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Rum>(); // TODO
                coord_ind++;
            } else if (f == "barrel"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Barrel>();
                coord_ind++;
            } else if (f == "cave"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Cave>();
                coord_ind++;
            } else if (f == "earthquake"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Earthquake>();
                coord_ind++;
            } else if (f == "jungle"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Jungle>();
                coord_ind++;
            } else if (f == "grass"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Grass>();
                coord_ind++;
            } else if (f == "boat"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Boat>();
                coord_ind++;
            } else if (f == "kernels"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Kernels>();
                coord_ind++;
            } else if (f == "cart"){
                m_field[random_coords[coord_ind].first][random_coords[coord_ind].second] =
                        std::make_unique<Cart>();
                coord_ind++;
            }
        }
    }
}