#include "GamerFactory.h"
#include <map>

OptimalFactory optimalFactory;
RandomFactory randomFactory;
ConsoleFactory consoleFactory;

std::map<std::string, GamerFactory*> factoryMap = {{"=optimal", &optimalFactory},
                                                   {"=random", &randomFactory},
                                                   {"=console", &consoleFactory}};

Gamer* factoryMethod(std::string type) {
    return factoryMap[type]->create();
}