#ifndef LAB0B_WORDCOUNTER_H
#define LAB0B_WORDCOUNTER_H


#include <map>
#include <iostream>
#include <fstream>
#include "stringParser.h"

class wordCounter {
    int wordNumber = 0;
    std::map<std::string, int> wordMap;

public:

    void parseFile(std::istream &fin);
    void printMap(std::ostream &fout);
};


#endif
