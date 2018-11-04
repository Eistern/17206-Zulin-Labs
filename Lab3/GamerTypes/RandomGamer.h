#ifndef LAB3_RANDOMGAMER_H
#define LAB3_RANDOMGAMER_H

#include "../Gamer.h"

class RandomGamer : public Gamer {
public:
    std::pair<char, unsigned int> setShip() override;
    std::pair<char, unsigned int> hitShip() override;
};


#endif //LAB3_RANDOMGAMER_H
