#include "Parser.h"

std::string Parser::getCmdName(std::istream& fin) {
    _shift = 0;
    getline(fin, _buff, '\n');

    if (_buff.find_first_of(" \n") != std::string::npos)
        _shift = _buff.find_first_of(" \n") + 1;
    else
        _shift = _buff.length();
    return {_buff, 0, _buff.find_first_of(" \n")};
}

std::list<std::string> Parser::getArguments() {
    std::list<std::string> argList;
    std::string _newArg;
    while (!(_newArg = this->getArgument()).empty())
        argList.push_back(_newArg);

    return argList;
}

std::string Parser::getArgument() {
    std::string tmp = _buff.substr(_shift);
    if (tmp.find_first_of(" \n") != std::string::npos)
        _shift += tmp.find_first_of(" \n") + 1;
    else
        _shift = _buff.length();

    return {tmp, 0, tmp.find_first_of(" \n")};
}