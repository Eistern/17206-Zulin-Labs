#include <iostream>
#include <fstream>
#include "wordCounter.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Wrong number of arguments" << std::endl;
        return 0;
    }
    std::ifstream fin(argv[1]);
    std::ofstream fout(argv[2]);

    wordCounter _new;
    _new.parseFile(fin);
    _new.printMap(fout);

    fout.close();
    fin.close();
    return 0;
}