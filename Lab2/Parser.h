#ifndef LAB2_PARSER_H
#define LAB2_PARSER_H

#include <iostream>
#include <list>

class Parser {
    std::string _buff = "";
    unsigned int _shift = 0;
public:
    std::string getCmdName(std::istream& _input);
    std::list<std::string> getArguments();
private:
    std::string getArgument();
};


#endif //LAB2_PARSER_H
