#ifndef LAB0B_STRINGPARSER_H
#define LAB0B_STRINGPARSER_H

#include <cctype>
#include <algorithm>
#include <string>
#include <queue>

class stringParser {
    std::queue<std::string> _array{};
public:
    //Function tidyString removes forbidden symbols from the string and converts it into lower case
    void parseString(std::string input) {
        int to = input.length();
        std::string buff;
        for (unsigned int i = 0; i < to; ++i) {
            if (isalpha(input.at(i)) || isdigit(input.at(i))) {
                buff += input.at(i);
            } else if (!buff.empty()) {
                transform(buff.begin(), buff.end(), buff.begin(), ::tolower);
                _array.push(buff);
                buff.clear();
            }
        }
    }

    //Function getString returns the front string from queue and deletes it
    std::string getString() {
        std::string result = _array.front();
        _array.pop();
        return result;
    }

    //Function isEmpty returns 1 if queue is empty
    bool isEmpty() {
        return _array.empty();
    }
};

#endif
