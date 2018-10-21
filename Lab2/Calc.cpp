#include "Calc.h"
#include "basicCommands.h"
#include "creators.h"
#include "Parser.h"
#include "CommandExeptions.h"

void Calc::run(std::istream &fin, std::ostream &fout) {
    Parser _streamListener;
    CmdCreator _newCreator;
    std::string cmdName;

    while (!fin.eof()) {
        cmdName = _streamListener.getCmdName(fin);
        if (cmdName.front() != '#') {
            Command *_newCommand = _newCreator.factoryMethod(cmdName);
            try {
                _newCommand->execute(this, _streamListener.getArguments());
            }
            catch (CommandExeptions &s) {
                std::cout << s.what() << std::endl;
            }

            std::cout << "Command " << cmdName << " executed" << std::endl;
            delete(_newCommand);
        }
    }
}

bool Calc::isDefined(const std::string &key) const {
    return _definedValues.find(key) != _definedValues.end();
}

double Calc::getDefine(const std::string &key) const {
    if (this->isDefined(key))
        return _definedValues.at(key);
}

void Calc::addDeifne(const std::string &key, double value) {
    _definedValues.insert({key, value});
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

double Calc::peek() const{
    return _activeStack.top();
}