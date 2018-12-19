#include <iostream>
#include <fstream>
#include "tuplePrinter.h"
#include "csvParser.h"

int main() {
    std::ifstream fin("test.csv");
    CSVParser<double, std::string> parser(fin, 0);
    for (auto pIt : parser)
        std::cout << pIt << std::endl;

    return 0;
}