#ifndef LAB3_OPTIMALGAMER_H
#define LAB3_OPTIMALGAMER_H

#include "../Gamer.h"

class OptimalGamer : public Gamer {
    bool _prevTurn = false;
public:
    std::pair<unsigned int, unsigned int> setShip() const override;
    std::pair<unsigned int, unsigned int> hitShip() const override;
    void setPrevTurn(bool value) override { _prevTurn = value; };
};


#endif //LAB3_OPTIMALGAMER_H
