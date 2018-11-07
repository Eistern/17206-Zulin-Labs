#ifndef LAB3_RANDOMGAMER_H
#define LAB3_RANDOMGAMER_H

#include "../Gamer.h"

class RandomGamer : public Gamer {
public:
    std::vector<unsigned int> setShip() const override;
    std::vector<unsigned int> hitShip() const override;
};


#endif //LAB3_RANDOMGAMER_H
