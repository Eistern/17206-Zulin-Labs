#ifndef LAB3_OPTIMALGAMER_H
#define LAB3_OPTIMALGAMER_H

#include "../Gamer.h"
#include <list>

class OptimalGamer : public Gamer {
    bool _permitted[10][10] = {{true}};
    std::list<std::vector<unsigned int>> _previousHits;
    int _maxUnfound = 4;
    int _hitDirection = 1;
    bool _reverse = false;
public:
    std::vector<unsigned int> setShip() override;
    std::vector<unsigned int> hitShip(const Board&) override;
private:
    void _updateMax(const Board&);
    void _markShip();
    bool _checkReverse(const Board&);
    std::vector<unsigned int> _findNext() const;
    std::vector<unsigned int> _continueHit() const;
};


#endif //LAB3_OPTIMALGAMER_H
