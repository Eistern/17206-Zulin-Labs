#include <iostream>
#include <fstream>
#include "tuplePrinter.h"
#include "csvParser.h"
#include <complex>

int main() {
    std::ifstream fin("test.csv");
    CSVParser<double, std::string, std::complex<double>> parser(fin, 0, ',', '\n');
    try {
        for (auto pIt : parser)
            std::cout << pIt << std::endl;
    }
    catch (const ParserExceptions &info) {
        std::cerr << info.what() << std::endl;
    }

    return 0;
}