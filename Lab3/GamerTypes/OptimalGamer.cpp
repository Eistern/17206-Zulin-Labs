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

std::vector<unsigned int> OptimalGamer::_continueHit() const {
    if (!_reverse) {
        if (_hitDirection == 1)
            return {_previousHit[0] + 1, _previousHit[1]};
        else
            return {_previousHit[0], _previousHit[1] + 1};
    } else {
        if (_hitDirection == 1)
            return {_previousHit[0] - 1, _previousHit[1]};
        else
            return {_previousHit[0], _previousHit[1] - 1};
    }

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

void OptimalGamer::_markShip(std::vector<unsigned int> choice, int size) {
    if (choice[2] == 1) {
        for (int i = (int)choice[0] - 1; i <= (int)choice[0] + size; ++i)
            for (int j = (int)choice[1] - 1; j <= (int)choice[1] + 1; ++j)
                if ((i >= 0 && i < 10) && (j >= 0 && j < 10))
                    _permitted[i][j] = false;
    } else {
        for (int j = (int)choice[1] - 1; j <= (int)choice[1] + size; ++j)
            for (int i = (int)choice[0] - 1; i <= (int)choice[0] + 1; ++i)
                if ((i >= 0 && i < 10) && (j >= 0 && j < 10))
                    _permitted[i][j] = false;
    }
}

bool OptimalGamer::_correctInfo(const Board &opponentBoard, std::vector<unsigned int> position) {
    int size = 0;
    unsigned x = position[0], y = position[1];
    if (_hitDirection == 1) {
        x--;
        while (x >= 0 && opponentBoard.getInfo({x, y}) == 3) {
            size++;
            x--;
        }
    } else {
        y--;
        while (y >= 0 && opponentBoard.getInfo({x, y}) == 3) {
            size++;
            y--;
        }
    }
    if ((size != 0) && (x < 0 || y < 0 || opponentBoard.getInfo({x, y}) == 2)) {
        if (_hitDirection == 1)
            _markShip({x + 1, y}, size);
        else
            _markShip({x, y + 1}, size);

        _reverse = false;
        _hitDirection = 1;
        return true;
    }
    if (opponentBoard.getInfo({x, y}) == -1) {
        if (size == 1)
            _hitDirection = (_hitDirection + 1) % 2;
        else {
            _reverse = true;
            if (_hitDirection == 1)
                _previousHit = {x + 1, y};
            else
                _previousHit = {x, y + 1};
        }
    }
    return false;
}

std::vector<unsigned int> OptimalGamer::hitShip(const Board& important) {
    _updateMax(important);

    if (important.getInfo(_previousHit) == 3) {
        //Сделать удар в зависимости направления и реверса, если возможно, иначе отметить и найти новое место
        _previousHit = _continueHit();
    } else {
        bool isDead = _correctInfo(important, _previousHit);
        if (isDead)
            _previousHit = _findNext();
        else
            _previousHit = _continueHit();
        //Проверить, подбит ли корабль, если подбит, то изменть _permitted и найти новую координату с помощью findNext
        //Если не подбит и длина не 1, то сделать _reverse
        //Если длина равна 1, то... пропустить
    }

    return _previousHit;
}

std::vector<unsigned int> OptimalGamer::setShip() {
//    std::vector<unsigned int> choice(3);
//
//    return choice;
}