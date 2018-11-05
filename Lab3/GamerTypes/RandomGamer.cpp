#include "RandomGamer.h"

std::vector<unsigned int> RandomGamer::setShip() const {
    std::random_device _rand;
    unsigned int x = _rand() % 10;
    unsigned int y = _rand() % 10;
    unsigned int dir = _rand() % 2;
    return {x, y, dir};
}

std::vector<unsigned int> RandomGamer::hitShip() const {
    std::random_device _rand;
    unsigned int x = _rand() % 10;
    unsigned int y = _rand() % 10;
    return {x, y};
}