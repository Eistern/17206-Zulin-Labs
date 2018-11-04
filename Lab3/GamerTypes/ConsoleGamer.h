#ifndef LAB3_CONSOLEGAMER_H
#define LAB3_CONSOLEGAMER_H

#include "../Gamer.h"

class ConsoleGamer : public Gamer {
public:
    std::pair<unsigned int, unsigned int> setShip() const override;
    std::pair<unsigned int, unsigned int> hitShip() const override;
};

#endif //LAB3_CONSOLEGAMER_H
