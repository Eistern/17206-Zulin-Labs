#include <iostream>
#include <fstream>
#include "Calc.h"

int main() {
    Calc _new;
    _new.run(std::cin, std::cout);
    std::cout << _new.peek();
    return 0;
}