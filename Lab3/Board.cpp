#include "Board.h"

int Board::getInfo(std::vector<unsigned int> choice) const {
    if (!gameStarted)
        return _board[choice[0]][choice[1]];
    else if (_board[choice[0]][choice[1]] == 2 || _board[choice[0]][choice[1]] == 3)
        return _board[choice[0]][choice[1]];

    return -1;
}

bool Board::hitShip(std::vector<unsigned int> choice) {
    if (_board[choice[0]][choice[1]] == 0) {
        _board[choice[0]][choice[1]] = 2;
        return false;
    } else {
        _board[choice[0]][choice[1]] = 3;
        return true;
    }
}

void Board::setShip(std::vector<unsigned int> choice, int size) {
    if (choice[2] == 1) {
        for (int i = choice[0]; i < choice[0] + size; ++i)
            _board[i][choice[1]] = 1;
    } else {
        for (int i = choice[1]; i < choice[1] + size; ++i)
            _board[choice[0]][i] = 1;
    }
}

bool Board::validateSet(std::vector<unsigned int> choice, int size) const {
    if (choice[2] == 1) {
        if (choice[0] + size > 10)
            return false;
        for (int i = (int)choice[0] - 1; i <= (int)choice[0] + size; ++i)
            for (int j = (int)choice[1] - 1; j <= (int)choice[1] + 1; ++j)
                if ((i >= 0 && i < 10) && (j >= 0 && j < 10) && _board[i][j] != 0)
                    return false;
    } else {
        if (choice[1] + size > 10)
            return false;
        for (int j = (int)choice[1] - 1; j <= (int)choice[1] + size; ++j)
            for (int i = (int)choice[0] - 1; i <= (int)choice[0] + 1; ++i)
                if ((i >= 0 && i < 10) && (j >= 0 && j < 10) && _board[i][j] != 0)
                    return false;
    }
    return true;
}

bool Board::validateHit(std::vector<unsigned int> choice) const {
    return _board[choice[0]][choice[1]] == 0 || _board[choice[0]][choice[1]] == 1;
}

bool Board::isWin() const {
    for (auto i : _board)
        for (int j = 0; j < 10; ++j)
            if (i[j] == 1)
                return false;

    return true;
}