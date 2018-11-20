#include "RandomGamer.h"
#include <random>

std::vector<unsigned int> RandomGamer::setShip() {
    static std::random_device seedGen;
    static std::default_random_engine generator(seedGen());
    static std::uniform_int_distribution<unsigned int> distribution(0,9);
    unsigned int x = distribution(generator);
    unsigned int y = distribution(generator);
    unsigned int dir = distribution(generator) % 2;
    return {x, y, dir};
}

std::vector<unsigned int> RandomGamer::hitShip(const Board& none) {
    static std::random_device seedGen;
    static std::default_random_engine generator(seedGen());
    static std::uniform_int_distribution<unsigned int> distribution(0,9);
    unsigned int x = distribution(generator);
    unsigned int y = distribution(generator);
    return {x, y};
}