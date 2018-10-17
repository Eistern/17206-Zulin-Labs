#include "Calc.h"

void Calc::run(const std::istream &fin, const std::ostream &fout) {
    //Parse input file, create element of command
}

int Calc::getDefine(const std::string& key) const {
    if (_definedValues.find(key) != _definedValues.end())
    return _definedValues[key];
}

void Calc::addDeifne(const std::string &key, int value) {
    _definedValues[key] = value;
}

unsigned int Calc::stackLength() const {
    return _activeStack.size();
}

void Calc::push(int _new) {
    _activeStack.push(_new);
}

int Calc::pop() {
    int temp = _activeStack.top();
    _activeStack.pop();
    return temp;
}