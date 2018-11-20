#ifndef LAB3_OPTIMALGAMER_H
#define LAB3_OPTIMALGAMER_H

#include "../Gamer.h"

class OptimalGamer : public Gamer {
    bool _permitted[10][10] = {{true}};
    std::vector<unsigned int> _previousHit =  {0, 0};
    int _hitDirection = 0;
    int _maxUnfound = 4;
public:
    std::vector<unsigned int> setShip() override;
    std::vector<unsigned int> hitShip(const Board&) override;
private:
    void _markShip(std::vector<unsigned int>, int size);
    bool _checkShip(const Board&, std::vector<unsigned int>);
    void _updateMax(const Board&);
    std::vector<unsigned int> _findNext() const;
};


#endif //LAB3_OPTIMALGAMER_H
