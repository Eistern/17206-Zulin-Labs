#ifndef LAB0B_STRINGPARSER_H
#define LAB0B_STRINGPARSER_H

#include <cctype>
#include <algorithm>
#include <string>
#include <cstring>

class stringParser {
    std::string forbidden;
public:
    //Default constructor makes all of punctuation marks forbidden
    stringParser () {
        forbidden = ",.;:()!?'\"\n";
    }

    //Function tidyString removes forbidden symbols from the string and converts it into lower case
    std::string tidyString(std::string input) {
        int to = input.length();
        for (unsigned int i = 0; i < to; ++i)
            while (i < to && std::strchr(forbidden.c_str(), input.at(i)) != nullptr) {
                input.erase(input.begin() + i);
                to = input.length();
            }
        while (input.at(0) == '-')
            input.erase(input.begin());

        transform(input.begin(), input.end(), input.begin(), ::tolower);
        return input;
    }
};

#endif
