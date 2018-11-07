#include "Battleships.h"

void Battleships::run(const Gamer &player1, const Gamer &player2, const GameView& screen, int count) const {
    for (int i = 0; i < count; ++i) {
        Board firstBoard;
        Board secondBoard;
        screen.sendMessage("---------------New round---------------\n");
        screen.sendMessage("-------First player placing ships------\n");
        placeStage(player1, firstBoard, screen);
        screen.sendMessage("------Second player placing ships------\n");
        placeStage(player2, secondBoard, screen);
        while (!firstBoard.isWin() && !secondBoard.isWin()) {
            screen.sendMessage("-------------First player turn--------\n");
            hitStage(player1, firstBoard, secondBoard, screen);
            screen.sendMessage("------------Second player turn--------\n");
            hitStage(player2, secondBoard, firstBoard, screen);
        }
        if (firstBoard.isWin())
            screen.sendMessage("Second player wins!");
        else
            screen.sendMessage("First player wins!");
    }
}

void Battleships::placeStage(const Gamer &player, Battleships::Board &playerBoard, const GameView &screen) const {
    std::vector<unsigned int> currentChoice;
    screen.sendMessage("Input coordinates and direction(H/W) of your ships\n");
    for (int length = 1; length < 5; ++length)
        for (int j = 0; j < 5 - length; ++j) {
            playerBoard.printBoard(true, screen);
            currentChoice = player.setShip();
            while (!playerBoard.validateSet(currentChoice, length)) {
                screen.sendMessage("Invalid placement, please try again\n");
                currentChoice = player.setShip();
            }
            playerBoard.setShip(currentChoice, length);
            system("pause");
        }
}

void Battleships::hitStage(const Gamer &player, Battleships::Board &playerBoard, Battleships::Board &opponentBoard, const GameView &screen) const {
    std::vector<unsigned int> currentChoice;
    playerBoard.printBoard(true, screen);
    opponentBoard.printBoard(false, screen);
    currentChoice = player.hitShip();
    while (!opponentBoard.validateHit(currentChoice)) {
        screen.sendMessage("Invalid hit(already hit this place), please try again\n");
        currentChoice = player.hitShip();
    }
    bool result = opponentBoard.hitShip(currentChoice);
}

bool Battleships::Board::hitShip(std::vector<unsigned int> choice) {
    if (_board[choice[0]][choice[1]] == 0) {
        _board[choice[0]][choice[1]] = 2;
        return false;
    } else {
        _board[choice[0]][choice[1]] = -1;
        return true;
    }
}

void Battleships::Board::setShip(std::vector<unsigned int> choice, int size) {
    if (choice[2] == 0) {
        for (int i = choice[0]; i < choice[0] + size; ++i)
            _board[i][choice[1]] = 1;
    } else {
        for (int i = choice[1]; i < choice[1] + size; ++i)
            _board[choice[0]][i] = 1;
    }
}

bool Battleships::Board::validateSet(std::vector<unsigned int> choice, int size) const {
    if (choice[2] == 0) {
        for (int i = choice[0] - 1; i <= choice[0] + size; ++i)
            for (int j = choice[1] - 1; j <= choice[1] + 1; ++j)
                if ((i >= 0 && i < 10) && (j >= 0 && j < 10) && _board[i][j] != 0)
                    return false;
    } else {
        for (int i = choice[1] - 1; i <= choice[1] + size; ++i)
            for (int j = choice[0] - 1; j <= choice[0] + 1; ++j)
                if ((i >= 0 && i < 10) && (j >= 0 && j < 10) && _board[i][j] != 0)
                    return false;
    }
    return true;
}

bool Battleships::Board::validateHit(std::vector<unsigned int> choice) const {
    return _board[choice[0]][choice[1]] != 0 && _board[choice[0]][choice[1]] != 1;
}

bool Battleships::Board::isWin() const {
    for (int i = 0; i < 10 ; ++i)
        for (int j = 0; j < 10; ++j)
            if (_board[i][j] == 1)
                return false;
    return true;
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
                        screen.sendMessage("~");
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