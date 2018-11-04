#ifndef LAB3_BATTLESHIPS_H
#define LAB3_BATTLESHIPS_H

#include <utility>

class Battleships {
public:
    void run();
    class Board {
        friend class Battleships;
        friend class ConsoleView;
        Board() = default;
        int _board[10][10] = {0};
    public:
        void setShip(std::pair<unsigned int, unsigned int>, char rotation, int size);
        bool hitShip(std::pair<unsigned int, unsigned int>);
        bool validateSet(std::pair<unsigned int, unsigned int>, char rotation, int size) const;
        bool validateHit(std::pair<unsigned int, unsigned int>) const;
    };
};


#endif //LAB3_BATTLESHIPS_H
