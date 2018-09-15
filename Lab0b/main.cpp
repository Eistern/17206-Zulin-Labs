#include <iostream>
#include <fstream>
#include "wordCounter.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Wrong number of arguments" << std::endl;
        return 1;
    }

    std::ifstream fin(argv[1]);
    if (!fin.is_open()) {
        std::cerr << "Error in opening file" << std::endl;
        return 2;
    }

    std::ofstream fout(argv[2]);
    if (!fout.is_open()) {
        std::cerr << "Error in opening file" << std::endl;
        return 2;
    }

    wordCounter counter;
    counter.parseFile(fin);
    counter.printMap(fout);

    fout.close();
    fin.close();
    return 0;
}