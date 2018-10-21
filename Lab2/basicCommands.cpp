#include "basicCommands.h"

void CommandDEFINE::execute(Calc *src, std::list<std::string> arg) {
    if (arg.size() != 2)
        return;

    double _newDefine = strtod(arg.back().c_str(), nullptr);
    arg.pop_back();
    std::string _defineKey = arg.back();

    if (src->isDefined(_defineKey))
        return;
    src->addDeifne(_defineKey, _newDefine);
}

void CommandPOP::execute(Calc *src, std::list<std::string> arg) {
    if (!arg.empty())
        return;

    src->pop();
}

void CommandPUSH::execute(Calc *src, std::list<std::string> arg) {
    if (arg.size() != 1)
        return;

    if (src->isDefined(arg.front()))
        src->push(src->getDefine(arg.front()));
    else
        src->push(strtod(arg.front().c_str(), nullptr));
}

void CommandPRINT::execute(Calc *src, std::list<std::string> arg) {
    if (src->stackLength() < 1)
        return;
    if (!arg.empty())
        return;

    std::cout << src->peek() << std::endl;
}

void CommandADD::execute(Calc *src, std::list<std::string> arg) {
    if (src->stackLength() < 2)
        return;
    if (!arg.empty())
        return;

    double arg1 = src->pop();
    double arg2 = src->pop();
    src->push(arg1 + arg2);
}

void CommandSUB::execute(Calc *src, std::list<std::string> arg) {
    if (src->stackLength() < 2)
        return;
    if (!arg.empty())
        return;

    double arg1 = src->pop();
    double arg2 = src->pop();
    src->push(arg2 - arg1);
}

void CommandMUL::execute(Calc *src, std::list<std::string> arg) {
    if (src->stackLength() < 2)
        return;
    if (!arg.empty())
        return;

    double arg1 = src->pop();
    double arg2 = src->pop();
    src->push(arg1 * arg2);
}

void CommandDIV::execute(Calc *src, std::list<std::string> arg) {
    if (src->stackLength() < 2)
        return;
    if (!arg.empty())
        return;

    double arg1 = src->pop();
    double arg2 = src->pop();
    src->push(arg2 / arg1);
}

void CommandSQRT::execute(Calc *src, std::list<std::string> arg) {
    if (src->stackLength() < 2)
        return;
    if (!arg.empty())
        return;

    double arg1 = src->pop();
    src->push(sqrt(arg1));
}