#ifndef LAB3_CONSOLEGAMER_H
#define LAB3_CONSOLEGAMER_H

#include "../Gamer.h"

class ConsoleGamer : public Gamer {
public:
    std::vector<unsigned int> setShip() const override;
    std::vector<unsigned int> hitShip(const Board&) const override;
};

#endif //LAB3_CONSOLEGAMER_H
