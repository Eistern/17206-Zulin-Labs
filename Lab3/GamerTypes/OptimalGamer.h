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
    bool _initialized = false;
public:
    OptimalGamer() {
        for (auto i : _permitted)
            for (int j = 0; j < 10; ++j)
                i[j] = true;
    }
    std::vector<unsigned int> setShip(const Board &, int) override;
    std::vector<unsigned int> hitShip(const Board &) override;
private:
    void _updateMax(const Board&);
    void _markShip();
    void _changeReverse();
    bool _updateDir(const Board &);
    std::vector<unsigned int> _findNext() const;
    std::vector<unsigned int> _continueHit() const;
};


#endif //LAB3_OPTIMALGAMER_H
