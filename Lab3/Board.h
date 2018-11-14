#ifndef LAB3_BOARD_H
#define LAB3_BOARD_H

#include <vector>

class Board {
    bool gameStarted = false;
    friend class Battleships;
    Board() = default;
    int _board[10][10] = {{0}};
public:
    int getInfo(std::vector<unsigned int>) const;
    void setShip(std::vector<unsigned int>, int size);
    bool hitShip(std::vector<unsigned int>);
    bool validateSet(std::vector<unsigned int>, int size) const;
    bool validateHit(std::vector<unsigned int>) const;
    bool isWin() const;
};

#endif //LAB3_BOARD_H
