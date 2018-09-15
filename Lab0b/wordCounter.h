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
    //Function parseFile gets a stream and process it to fill the wordMap
    void parseFile(std::istream &fin);
    //Function printMap prints out wordMap in decreasing order by usage
    void printMap(std::ostream &fout);
};


#endif
