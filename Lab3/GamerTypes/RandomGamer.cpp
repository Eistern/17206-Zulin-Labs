#include "RandomGamer.h"

std::pair<unsigned int, unsigned int> RandomGamer::setShip() {
    unsigned int x = _rand() % 10;
    unsigned int y = _rand() % 10;
    return {x, y};
}

std::pair<unsigned int, unsigned int> RandomGamer::hitShip() {
    unsigned int x = _rand() % 10;
    unsigned int y = _rand() % 10;
    return {x, y};
}