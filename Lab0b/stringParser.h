#ifndef LAB0B_STRINGPARSER_H
#define LAB0B_STRINGPARSER_H

#include <cctype>
#include <algorithm>
#include <string>

class stringParser {
public:
    //Function tidyString removes forbidden symbols from the string and converts it into lower case
    std::string tidyString(std::string input) {
        int to = input.length();
        for (unsigned int i = 0; i < to; ++i)
            while (i < to && !(isalpha(input.at(i)) || isdigit(input.at(i)))) {
                input.erase(input.begin() + i);
                to = input.length();
            }

        transform(input.begin(), input.end(), input.begin(), ::tolower);
        return input;
    }
};

#endif
