#include "Battleships.h"

void Battleships::run(const Gamer &player1, const Gamer &player2, const GameView& screen, int count) const {
    for (int i = 0; i < count; ++i) {
        Board firstBoard;
        Board secondBoard;
        screen.sendMessage("---------------New round---------------\n");
        screen.sendMessage("-------First player placing ships------\n");
        initBoard(player1, firstBoard, screen);
        screen.sendMessage("------Second player placing ships------\n");
        initBoard(player2, secondBoard, screen);
    }
}

void Battleships::initBoard(const Gamer &player, const Battleships::Board &playerBoard, const GameView& screen) const {
    std::pair<unsigned int, unsigned int> currentChoice = {11, 11};
    screen.sendMessage("Input ");
    for (int length = 1; length < 5; ++length)
        for (int j = 0; j < 5 - length; ++j) {
            currentChoice = player.setShip();
            while (!playerBoard.validateSet(currentChoice)) {
                screen.sendMessage("Invalid placement\n");
                currentChoice = player.setShip();
            }
            playerBoard.printBoard(true, screen);
        }
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
    if (rotation == 'H') {
        if (choice.first + size - 1 >= 10)
            return false;
        for (int i = choice.first - 1; i <= choice.first + size; ++i)
            for (int j = choice.second - 1; j <= choice.second + 1; ++j)
                if ((i >= 0 && i < 10) && (j >= 0 && j < 10) && _board[i][j] != 0)
                    return false;
    } else {
        if (choice.second + size - 1 >= 10)
            return false;
        for (int i = choice.second - 1; i <= choice.second + size; ++i)
            for (int j = choice.first - 1; j <= choice.first + 1; ++j)
                if ((i >= 0 && i < 10) && (j >= 0 && j < 10) && _board[i][j] != 0)
                    return false;
    }
    return true;
}

bool Battleships::Board::validateHit(std::pair<unsigned int, unsigned int> choice) const {
    return _board[choice.first][choice.second] != 0 && _board[choice.first][choice.second] != 1;
}

void Battleships::Board::printBoard(bool printAll, const GameView& screen) const {
    if (printAll) {
        screen.sendMessage("-----Your board------\n");
        screen.sendMessage("+ABCDEFGHIJ\n");
        for (unsigned int i = 0; i < 10; ++i) {
            screen.sendMessage(i);
            for (unsigned int j = 0; j < 10; ++j)
                switch (_board[i][j]) {
                    case 0 :
                        screen.sendMessage("~");
                        break;
                    case 1 :
                        screen.sendMessage("O");
                        break;
                    case 2 :
                        screen.sendMessage(".");
                        break;
                    case -1 :
                        screen.sendMessage("+");
                        break;
                    default:
                        break;
                }
            screen.sendMessage("\n");
        }
    } else {
        screen.sendMessage("-----Opponent's board------\n");
        screen.sendMessage("+ABCDEFGHIJ\n");
        for (unsigned int i = 0; i < 10; ++i) {
            screen.sendMessage(i);
            for (unsigned int j = 0; j < 10; ++j)
                switch (_board[i][j]) {
                    case 2 :
                        screen.sendMessage(".");
                        break;
                    case -1 :
                        screen.sendMessage("+");
                        break;
                    default:
                        screen.sendMessage("?");
                        break;
                }
            screen.sendMessage("\n");
        }
    }
}