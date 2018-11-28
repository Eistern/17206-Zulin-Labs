#include "OptimalGamer.h"

#define CRITICAL_COUNT 25

std::vector<unsigned int> OptimalGamer::_findNext() const {
    unsigned int pos = 0;
    int count = 0;
    while (!_permitted[pos % 10][pos / 10]) {
        pos += _maxUnfound;
        if (pos >= 100) {
            pos %= 100;
            count++;
        }
        if (count == CRITICAL_COUNT)
            pos++;
    }
    return {pos % 10, pos / 10};
}

void OptimalGamer::_updateMax(const Board &opponentBoard) {
    int count[5] = {0};
    int size = 0;

    for (unsigned int i = 0; i < 10; ++i)
        for (unsigned int j = 0; j < 10; ++j)
            if (opponentBoard.getInfo({i, j}) == 3)
                size++;
            else {
                count[size]++;
                size = 0;
            }

    for (unsigned int j = 0; j < 10; ++j)
        for (unsigned int i = 0; i < 10; ++i)
            if (opponentBoard.getInfo({i, j}) == 3)
                size++;
            else {
                count[size]++;
                size = 0;
            }

    if (count[4] == 1)
        _maxUnfound = 3;
    else
        _maxUnfound = 4;
    if (count[3] == 2 && _maxUnfound == 3)
        _maxUnfound = 2;
    if (count[2] == 3 && _maxUnfound == 2)
        _maxUnfound = 1;
}

std::vector<unsigned int> OptimalGamer::_continueHit() const {
    std::vector<unsigned int> choice = _previousHits.back();
    int shift = _reverse ? -1 : 1;
    if (_hitDirection == 1)
        choice[0] += shift;
    else
        choice[1] += shift;

    return choice;
}

bool OptimalGamer::_checkReverse(const Board &) {
    auto it = _previousHits.rbegin();
    unsigned int constCoord = _hitDirection == 1 ? 0 : 1;
    int constValue = _previousHits.back()[constCoord];
    it++;

    if (it != _previousHits.rend() && it.operator*().at(constCoord) == constValue)
        return false;

    _reverse = true;
    _previousHits.reverse();
    return true;
}

std::vector<unsigned int> OptimalGamer::hitShip(const Board &opponentBoard) {
    _updateMax(opponentBoard);
    std::vector<unsigned int> predict;

    if (opponentBoard.getInfo(_previousHits.back()) == 3) {
        predict = _continueHit();
        if (!((predict[0] >= 0 && predict[0] < 10) && (predict[1] >= 0 && predict[1] < 10)))
            if
    }

    _previousHits.push_back(predict);
    return predict;
}

std::vector<unsigned int> OptimalGamer::setShip() {

}