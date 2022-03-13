#ifndef SHIP_H_
#define SHIP_H_

#include <QLabel>
#include <utility>

namespace jackal {

    class Ship : public QObject {
    Q_OBJECT
    public:
        Ship(int col, int row);

        std::pair<int, int> get_coords();

    signals:
        void shipMove();

    private:
        int m_col;
        int m_row;
    };

}
#endif // SHIP_H_
