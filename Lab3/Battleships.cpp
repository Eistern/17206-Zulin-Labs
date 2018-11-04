#include "Battleships.h"

void Battleships::run() {

}

bool Battleships::Board::hitShip(std::pair<unsigned int, unsigned int> choice) {
    if (_board[choice.first][choice.second] == 0) {
        _board[choice.first][choice.second] = 2;
        return false;
    } else {
        _board[choice.first][choice.second] = -1;
        return true;
    }
}

void Battleships::Board::setShip(std::pair<unsigned int, unsigned int> choice, char rotation, int size) {
    if (rotation == 'H') {
        for (int i = choice.first; i < choice.first + size; ++i)
            _board[i][choice.second] = 1;
    } else {
        for (int i = choice.second; i < choice.second + size; ++i)
            _board[choice.first][i] = 1;
    }
}

bool Battleships::Board::validateSet(std::pair<unsigned int, unsigned int> choice, char rotation, int size) const {

}

bool Battleships::Board::validateHit(std::pair<unsigned int, unsigned int> choice) const {
    return _board[choice.first][choice.second] != 0 && _board[choice.first][choice.second] != 1;
}