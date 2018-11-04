#include <iostream>
#include "ConsoleView.h"

void ConsoleView::updateBoard(const Battleships::Board &playerBoard, const Battleships::Board &opponentBoard) {
    std::cout << "-----Your board------" << std::endl;
    std::cout << "+ABCDEFGHIJ" << std::endl;
    for (unsigned int i = 0; i < 10; ++i) {
        std::cout << i;
        for (unsigned int j = 0; j < 10; ++j)
            switch (playerBoard._board[i][j]) {
                case 0 :
                    std::cout << "~";
                    break;
                case 1 :
                    std::cout << "O";
                    break;
                case 2 :
                    std::cout << ".";
                    break;
                case -1 :
                    std::cout << "+";
                    break;
                default:
                    break;
            }
        std::cout << std::endl;
    }
    std::cout << "-----Opponent's board------" << std::endl;
    std::cout << "+ABCDEFGHIJ" << std::endl;
    for (unsigned int i = 0; i < 10; ++i) {
        std::cout << i;
        for (unsigned int j = 0; j < 10; ++j)
            switch (playerBoard._board[i][j]) {
                case 2 :
                    std::cout << ".";
                    break;
                case -1 :
                    std::cout << "+";
                    break;
                default:
                    std::cout << "?";
                    break;
            }
        std::cout << std::endl;
    }
}

void ConsoleView::sendMessage(const std::string &message) {
    std::cout << message << std::endl;
}