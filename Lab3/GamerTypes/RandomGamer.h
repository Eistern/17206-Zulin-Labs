#ifndef LAB3_RANDOMGAMER_H
#define LAB3_RANDOMGAMER_H

#include "../Gamer.h"
#include <random>

class RandomGamer : public Gamer {
    std::random_device _rand;
public:
    std::pair<unsigned int, unsigned int> setShip() const override;
    std::pair<unsigned int, unsigned int> hitShip() const override;
    ~RandomGamer() override = default;
};


#endif //LAB3_RANDOMGAMER_H
