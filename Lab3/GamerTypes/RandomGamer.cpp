#include "RandomGamer.h"
#include <random>
#include <ctime>

std::vector<unsigned int> RandomGamer::setShip() {
    static std::default_random_engine generator(static_cast<unsigned int>(time(nullptr)));
    static std::uniform_int_distribution<unsigned int> distribution(0,9);
    unsigned int x = distribution(generator);
    unsigned int y = distribution(generator);
    unsigned int dir = distribution(generator) % 2;
    return {x, y, dir};
}

std::vector<unsigned int> RandomGamer::hitShip(const Board& checker) {
    static std::default_random_engine generator(static_cast<unsigned int>(time(nullptr)));
    static std::uniform_int_distribution<unsigned int> distribution(0,9);
    unsigned int x = distribution(generator);
    unsigned int y = distribution(generator);
    while (!checker.validateHit({x, y})) {
        x = distribution(generator);
        y = distribution(generator);
    }
    return {x, y};
}