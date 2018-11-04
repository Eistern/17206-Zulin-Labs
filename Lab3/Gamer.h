#ifndef LAB3_GAMER_H
#define LAB3_GAMER_H

#include <utility>
//TODO change signatue of setShip and hitShip
//TODO implenemt types of players

class Gamer {
public:
    virtual std::pair<unsigned int, unsigned int> setShip() const = 0;
    virtual std::pair<unsigned int, unsigned int> hitShip() const = 0;
    virtual void setPrevTurn(bool) {};
    virtual ~Gamer() = default;
};

#endif //LAB3_GAMER_H
