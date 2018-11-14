#include "ConsoleGamer.h"
#include <iostream>

std::vector<unsigned int> ConsoleGamer::setShip() const {
    int x;
    unsigned char y, dir;
    std::cout << "Please input coord of your next ship(line/row/direction):\n";
    std::cin >> x >> y >> dir;
    while (!(x >= 0 && x < 10) || !(y >= 'A' && y <= 'J') || !(dir == 'H' || dir == 'W')) {
        std::cout << "Invalid format, please try again" << std::endl;
        std::cin >> x >> y >> dir;
    }
    std::vector<unsigned int> result(3);
    result[0] = static_cast<unsigned int>(x);
    result[1] = y - 'A';
    result[2] = dir == 'H' ? 0 : 1;
    return result;
}

std::vector<unsigned int> ConsoleGamer::hitShip(const Board& none) const {
    int x;
    unsigned char y;
    std::cout << "Please input coord of your hit(line/row): ";
    std::cin >> x >> y;
    while (!(x >= 0 && x < 10) || !(y >= 'A' && y <= 'J')) {
        std::cout << "Invalid format, please try again" << std::endl;
        std::cin >> x >> y;
    }
    std::vector<unsigned int> result(2);
    result[0] = static_cast<unsigned int>(x);
    result[1] = y - 'A';
    return result;
}