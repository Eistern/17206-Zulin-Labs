#ifndef LAB3_CONSOLEGAMER_H
#define LAB3_CONSOLEGAMER_H

#include "../Gamer.h"

class ConsoleGamer : public Gamer {
public:
    std::pair<char, unsigned int> setShip() override;
    std::pair<char, unsigned int> hitShip() override;
};

#endif //LAB3_CONSOLEGAMER_H
