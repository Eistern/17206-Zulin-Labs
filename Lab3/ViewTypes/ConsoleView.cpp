#include "ConsoleView.h"
#include <iostream>

void ConsoleView::sendMessage(const std::string &message) const {
    std::cout << message;
}

void ConsoleView::printBoard() const {

}