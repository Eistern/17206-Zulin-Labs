#include "Calc.h"
#include "cmdFactory.h"
#include "Parser.h"
#include "CommandExeptions.h"

void Calc::run(std::istream &fin, std::ostream &fout) {
    Context _calcContext;
    Parser _streamListener;
    std::string cmdName;

    while (!fin.eof()) {
        cmdName = _streamListener.getCmdName(fin);
        if (cmdName.front() != '#') {
            try {
                Command *_newCommand = cmdFactory::getInstance()->getCommand(cmdName);
                try {
                    _newCommand->execute(&_calcContext, _streamListener.getArguments());
                }
                catch (const CommandExeptions &s) {
                    std::cerr << s.what() << std::endl;
                }

                std::cout << "Command " << cmdName << " executed" << std::endl;
                delete (_newCommand);
            }
            catch (const command_not_found &s) {
                std::cerr << s.what() << std::endl;
            }
        }
    }
}

bool Calc::Context::isDefined(const std::string &key) const {
    return _definedValues.find(key) != _definedValues.end();
}

double Calc::Context::getDefine(const std::string &key) const {
    return _definedValues.at(key);
}

void Calc::Context::addDeifne(const std::string &key, double value) {
    _definedValues.insert({key, value});
}

unsigned long long int Calc::Context::stackLength() const {
    return _activeStack.size();
}

void Calc::Context::push(double _new) {
    _activeStack.push(_new);
}

double Calc::Context::pop() {
    double temp = _activeStack.top();
    _activeStack.pop();
    return temp;
}

double Calc::Context::peek() const{
    return _activeStack.top();
}