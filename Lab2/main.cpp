#include <iostream>
#include <fstream>
#include "Calc.h"

int main(int argc, char *argv[]) {
    Calc _new;
    if (argc == 2) {
        std::ifstream fin(argv[1]);
        if (!fin.is_open()) {
            std::cerr << "Error in opening file" << std::endl;
            return 1;
        }
        _new.run(fin, std::cout);
    } else
        _new.run(std::cin, std::cout);

    return 0;
}