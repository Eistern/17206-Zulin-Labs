#ifndef LAB3_GAMER_H
#define LAB3_GAMER_H

#include <vector>
//TODO change signatue of setShip and hitShip
//TODO implenemt types of players

class Gamer {
public:
    virtual std::vector<unsigned int> setShip() const = 0;
    virtual std::vector<unsigned int> hitShip() const = 0;
    virtual void setPrevTurn(bool) {};
    virtual ~Gamer() = default;
};

#endif //LAB3_GAMER_H
