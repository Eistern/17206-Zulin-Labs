#include "Calc.h"
#include "basicCommands.h"
#include "creators.h"

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