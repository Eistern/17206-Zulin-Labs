#ifndef LAB3_RANDOMGAMER_H
#define LAB3_RANDOMGAMER_H

#include "../Gamer.h"
#include <random>

class RandomGamer : public Gamer {
    std::random_device _rand;
public:
    std::pair<unsigned int, unsigned int> setShip() override;
    std::pair<unsigned int, unsigned int> hitShip() override;
    ~RandomGamer() override = default;
};


#endif //LAB3_RANDOMGAMER_H
