#ifndef LAB3_GAMER_H
#define LAB3_GAMER_H

#include <utility>

class Gamer {
public:
    virtual std::pair<unsigned int, unsigned int> setShip() = 0;
    virtual std::pair<unsigned int, unsigned int> hitShip() = 0;
    virtual void setPrevTurn(bool) {};
    virtual ~Gamer() = default;
};

#endif //LAB3_GAMER_H
