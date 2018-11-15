#ifndef LAB3_OPTIMALGAMER_H
#define LAB3_OPTIMALGAMER_H

#include "../Gamer.h"

class OptimalGamer : public Gamer {
    static int _probability[10][10];

    std::vector<unsigned int> _previousHit =  {0, 0};
public:
    std::vector<unsigned int> setShip() const override;
    std::vector<unsigned int> hitShip(const Board&) const override;
};


#endif //LAB3_OPTIMALGAMER_H
