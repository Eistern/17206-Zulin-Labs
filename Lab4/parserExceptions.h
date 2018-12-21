#ifndef LAB4_PARSEREXEPTIONS_H
#define LAB4_PARSEREXEPTIONS_H

#include <exception>
#include <sstream>
#include <string>
#include <cstring>

class ParserExceptions : public std::exception {
public:
    const char* what() const noexcept override = 0;
};

class columnFailure : public ParserExceptions {
public:
    int _columnNumber;
    explicit columnFailure(int column) : _columnNumber(column) {};
    const char* what() const noexcept override { return ""; };
};

class readFailure : public ParserExceptions {
    int _columnNumber;
    int _lineNumber;
    std::string _resultMessage;
public:
    readFailure(int column, int line) : _columnNumber(column), _lineNumber(line) {
        std::stringstream result;
        result << "Reading failure at " << _lineNumber << " line, at " << _columnNumber << " column";
        std::string buff = result.str();
        _resultMessage = buff;
    };
    const char* what() const noexcept override {
        return _resultMessage.c_str();
    };
};


#endif //LAB4_PARSEREXEPTIONS_H
