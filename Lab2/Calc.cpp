#include "Calc.h"

void Calc::run(const std::istream &fin, const std::ostream &fout) {
    //Parse input file, create element of command
    cmdCreator _newCreator;
    command* _new = _newCreator.factoryMethod("PUSH");
    _new->execute(this, {"1"});
}

bool Calc::isDefined(const std::string &key) const {
    return _definedValues.find(key) != _definedValues.end();
}

double Calc::getDefine(const std::string &key) const {
    if (this->isDefined(key))
        return _definedValues.at(key);
}

void Calc::addDeifne(const std::string &key, double value) {
    _definedValues.at(key) = value;
}

unsigned int Calc::stackLength() const {
    return _activeStack.size();
}

void Calc::push(double _new) {
    _activeStack.push(_new);
}

double Calc::pop() {
    double temp = _activeStack.top();
    _activeStack.pop();
    return temp;
}

double Calc::peek() {
    return _activeStack.top();
}

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

pushCreator _push;
popCreator _pop;
addCreator _add;
subCreator _sub;
mulCreator _mul;
divCreator _div;
sqrtCreator _sqrt;
defineCreator _define;

const std::map<std::string, cmdCreator*> cmdCreator::_creatorArray = { {"PUSH", &_push},
                                                                       {"POP", &_pop},
                                                                 {"+",  &_add},
                                                                 {"-", &_sub},
                                                                       {"*", &_mul},
                                                                       {"/", &_div},
                                                                       {"SQRT", &_sqrt},
                                                                 {"DEFINE", &_define}
};