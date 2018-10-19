#include "basicCommands.h"

void commandDEFINE::execute(Calc *src, std::list<std::string> arg) {
    if (arg.size() != 2)
        return;

    double _newDefine = strtod(arg.back().c_str(), nullptr);
    arg.pop_back();
    std::string _defineKey = arg.back();
    src->addDeifne(_defineKey, _newDefine);
}

void commandPOP::execute(Calc *src, std::list<std::string> arg) {
    if (arg.size() != 0)
        return;

    src->pop();
}

void commandPUSH::execute(Calc *src, std::list<std::string> arg) {
    if (arg.size() != 1)
        return;

    if (src->isDefined(arg.front()))
        src->push(src->getDefine(arg.front()));
    else
        src->push(strtod(arg.front().c_str(), nullptr));
}

void commandADD::execute(Calc *src, std::list<std::string> arg) {
    if (src->stackLength() < 2)
        return;
    if (arg.size() != 0)
        return;

    double arg1 = src->pop();
    double arg2 = src->pop();
    src->push(arg1 + arg2);
}

void commandSUB::execute(Calc *src, std::list<std::string> arg) {
    if (src->stackLength() < 2)
        return;
    if (arg.size() != 0)
        return;

    double arg1 = src->pop();
    double arg2 = src->pop();
    src->push(arg2 - arg1);
}

void commandMUL::execute(Calc *src, std::list<std::string> arg) {
    if (src->stackLength() < 2)
        return;
    if (arg.size() != 0)
        return;

    double arg1 = src->pop();
    double arg2 = src->pop();
    src->push(arg1 * arg2);
}

void commandDIV::execute(Calc *src, std::list<std::string> arg) {
    if (src->stackLength() < 2)
        return;
    if (arg.size() != 0)
        return;

    double arg1 = src->pop();
    double arg2 = src->pop();
    src->push(arg2 / arg1);
}

void commandSQRT::execute(Calc *src, std::list<std::string> arg) {
    if (src->stackLength() < 2)
        return;
    if (arg.size() != 0)
        return;

    double arg1 = src->pop();
    src->push(sqrt(arg1));
}