#include "ConsoleView.h"
#include <iostream>

void ConsoleView::sendMessage(const std::string &message) const {
    std::cout << message;
}

void ConsoleView::printBoard(const Board &playerBoard) const {
    std::cout << "+ABCDEFGHIJ" << std::endl;
    for (unsigned int i = 0; i < 10; ++i) {
        std::cout << i;
        for (unsigned int j = 0; j < 10; ++j)
            switch (playerBoard.getInfo({i, j})) {
                case 0 :
                    std::cout << "~";
                    break;
                case 1 :
                    std::cout << "O";
                    break;
                case 2 :
                    std::cout << "-";
                    break;
                case 3 :
                    std::cout << "+";
                    break;
                default:
                    std::cout << "?";
                    break;
            }
        std::cout << std::endl;
    }
}