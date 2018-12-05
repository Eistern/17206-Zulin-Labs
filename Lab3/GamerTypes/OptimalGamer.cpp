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

bool OptimalGamer::_changeReverse() {
    _reverse = !_reverse;
    _previousHits.reverse();
}

void OptimalGamer::_markShip() {
    std::vector<unsigned int> buff;
    while (!_previousHits.empty()) {
        buff = _previousHits.back();
        for (int i = (int)buff[0] - 1; i <= (int)buff[0] + 1; ++i)
            for (int j = (int)buff[1] - 1; j <= (int)buff[1] + 1; ++j)
                if ((i >= 0 && i < 10) && (j >= 0 && j < 10))
                    _permitted[i][j] = false;
        _previousHits.pop_back();
    }
    _hitDirection = 1;
    _reverse = false;
}

bool OptimalGamer::_updateDir(const Board &opponentBoard) {
    std::vector<unsigned int> test;

    if (_previousHits.size() != 1) {
        _changeReverse();
        test = _continueHit();
        if (opponentBoard.getInfo(test) == 2)
            return false;
    } else {
        if (_hitDirection == 1) {
            if (_reverse) {
                _hitDirection = 0;
                _reverse = false;
            }
            else
                _reverse = true;
        } else {
            if (_reverse)
                return false;
            else
                _reverse = true;
        }

    }
    return true;
}

std::vector<unsigned int> OptimalGamer::hitShip(const Board &opponentBoard) {
    _updateMax(opponentBoard);
    std::vector<unsigned int> predict;

    if (opponentBoard.getInfo(_previousHits.back()) == 3) {
        predict = _continueHit();
        if (_previousHits.size() == 4) {
            _markShip();
            predict = _findNext();
        } else if (!((predict[0] >= 0 && predict[0] < 10) && (predict[1] >= 0 && predict[1] < 10))) {
            _changeReverse();
            predict = _continueHit();
            if (opponentBoard.getInfo(predict) == 2 || !_permitted[predict[0]][predict[1]]) {
                _markShip();
                predict = _findNext();
            }
        }
    } else {
        _previousHits.pop_back();
        if (_previousHits.empty()) {
            _permitted[_previousHits.back()[0]][_previousHits.back()[1]] = false;
            predict = _findNext();
        }
        else {
            bool notDead = _updateDir(opponentBoard);
            if (notDead)
                predict = _continueHit();
            else
                predict = _findNext();
        }
    }

    _previousHits.push_back(predict);
    return predict;
}

std::vector<unsigned int> OptimalGamer::setShip() {

}