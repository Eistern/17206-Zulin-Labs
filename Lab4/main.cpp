#include <iostream>
#include <fstream>
#include "tuplePrinter.h"
#include "csvParser.h"

int main() {
    std::ifstream fin("test.csv");
    CSVParser<int, std::string> parser(fin, 0);
    for (auto pIt : parser)


    return 0;
}