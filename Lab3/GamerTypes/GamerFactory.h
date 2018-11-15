#ifndef LAB3_GAMERFACTORY_H
#define LAB3_GAMERFACTORY_H

#include <string>
#include "ConsoleGamer.h"
#include "OptimalGamer.h"
#include "RandomGamer.h"

Gamer* factoryMethod(std::string);

class GamerFactory {
public:
    virtual Gamer* create() const = 0;
};

class ConsoleFactory : public GamerFactory {
public:
    Gamer* create() const override { return new ConsoleGamer; };
};

class OptimalFactory : public GamerFactory {
    Gamer* create() const override { return new OptimalGamer; };
};

class RandomFactory : public GamerFactory {
    Gamer* create() const override { return new RandomGamer; };
};


#endif //LAB3_GAMERFACTORY_H
