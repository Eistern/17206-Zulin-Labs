#ifndef LAB3_GAMER_H
#define LAB3_GAMER_H

#include <vector>
#include "Board.h"
//TODO implenemt optimalGamer

class Gamer {
public:
    virtual std::vector<unsigned int> setShip() = 0;
    virtual std::vector<unsigned int> hitShip(const Board&) = 0;
    virtual ~Gamer() = default;
};

#endif //LAB3_GAMER_H
