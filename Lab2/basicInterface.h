#ifndef LAB2_BASICINTERFACE_H
#define LAB2_BASICINTERFACE_H

#include "Calc.h"
#include <list>

class Command {
public:
    virtual void execute(Calc::Context *src, const std::list<std::string> &arg) = 0;
    virtual ~Command() = default;
};

class CmdCreator {
public:
    virtual Command* create() = 0;
};

#endif //LAB2_BASICINTERFACE_H
