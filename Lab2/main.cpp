#include <iostream>
#include <fstream>
#include "Calc.h"
#include "Parser.h"

int main(int argc, char *argv[]) {
    std::ifstream fin(argv[1]);
    if (!fin.is_open()) {
        std::cerr << "Error in opening file" << std::endl;
        return 2;
    }

    Calc _new;
    _new.run(fin, std::cout);
    return 0;
}