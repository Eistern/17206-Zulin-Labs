#ifndef LAB3_OPTIMALGAMER_H
#define LAB3_OPTIMALGAMER_H

#include "../Gamer.h"

class OptimalGamer : public Gamer {
public:
    std::pair<char, unsigned int> setShip() override;
    std::pair<char, unsigned int> hitShip() override;
};


#endif //LAB3_OPTIMALGAMER_H
