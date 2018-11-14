#ifndef LAB3_OPTIMALGAMER_H
#define LAB3_OPTIMALGAMER_H

#include "../Gamer.h"

class OptimalGamer : public Gamer {
public:
    std::vector<unsigned int> setShip() const override;
    std::vector<unsigned int> hitShip() const override;
};


#endif //LAB3_OPTIMALGAMER_H
