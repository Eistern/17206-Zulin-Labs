#ifndef LAB3_OPTIMALGAMER_H
#define LAB3_OPTIMALGAMER_H

#include "../Gamer.h"

class OptimalGamer : public Gamer {
    bool _prevTurn = false;
public:
    std::vector<unsigned int> setShip() const override;
    std::vector<unsigned int> hitShip() const override;
    void setPrevTurn(bool value) override { _prevTurn = value; };
};


#endif //LAB3_OPTIMALGAMER_H
