#ifndef LAB3_GAMER_H
#define LAB3_GAMER_H

#include <utility>

class Gamer {
public:
    virtual std::pair<char, unsigned int> setShip() = 0;
    virtual std::pair<char, unsigned int> hitShip() = 0;
    virtual ~Gamer() = default;
};

#endif //LAB3_GAMER_H
