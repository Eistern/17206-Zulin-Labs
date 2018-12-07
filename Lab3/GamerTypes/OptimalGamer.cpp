#include "OptimalGamer.h"
#include <random>
#include <ctime>

#define CRITICAL_COUNT 25
#define MIN_INT (-2147483647)

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

void OptimalGamer::_changeReverse() {
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
        if (!_permitted[test[0]][test[1]] || opponentBoard.getInfo(test) == 2 || opponentBoard.getInfo(test) == MIN_INT)
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

bool inline OptimalGamer::_correctPredict(std::vector<unsigned int> predict) const {
    return ((predict[0] >= 0 && predict[0] < 10) && (predict[1] >= 0 && predict[1] < 10));
}

std::vector<unsigned int> OptimalGamer::hitShip(const Board &opponentBoard) {
    _updateMax(opponentBoard);
    std::vector<unsigned int> predict(2);

    if (!_initialized) {
        _initialized = true;
        predict[0] = 5;
        predict[1] = 5;
        _previousHits.push_back(predict);
        return predict;
    }

    if (opponentBoard.getInfo(_previousHits.back()) == 3) {
        predict = _continueHit();
        if (_previousHits.size() == 4) {
            _markShip();
            predict = _findNext();
        } else if (!_correctPredict(predict)) {
            bool notDead = _updateDir(opponentBoard);
            if (notDead)
                predict = _continueHit();
            else {
                _markShip();
                predict = _findNext();
            }
        }
    } else {
        _permitted[_previousHits.back()[0]][_previousHits.back()[1]] = false;
        _previousHits.pop_back();
        if (_previousHits.empty()) {
            predict = _findNext();
        }
        else {
            bool notDead = _updateDir(opponentBoard);
            if (notDead) {
                predict = _continueHit();
                while ((!_correctPredict(predict) && notDead) || ((!_permitted[predict[0]][predict[1]] || opponentBoard.getInfo(predict) == 2) && notDead)) {
                    notDead = _updateDir(opponentBoard);
                    predict = _continueHit();
                }
                if (!notDead) {
                    _markShip();
                    predict = _findNext();
                }
            }
            else {
                _markShip();
                predict = _findNext();
            }
        }
    }

    _previousHits.push_back(predict);
    return predict;
}

std::vector<unsigned int> OptimalGamer::setShip(const Board &playerBoard, const int length) {
    unsigned int shift = 0;
    static std::default_random_engine generator(static_cast<unsigned int>(time(nullptr)));
    static std::uniform_int_distribution<unsigned int> distribution(0,9);
    unsigned int dir = distribution(generator) % 2;
    unsigned int startX = distribution(generator);
    unsigned int startY = distribution(generator);
    while (!playerBoard.validateSet({startX, startY, dir}, length)) {
        startX++;
        if (startX >= 10) {
            startX = 0;
            startY++;
        }
        if (startY >= 10) {
            startX = shift;
            startY = shift;
            shift++;
        }
        if (shift > CRITICAL_COUNT)
            dir = (dir + 1) % 2;
    }
    return {startX, startY, dir};
}