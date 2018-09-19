#ifndef LAB1_TRISET_H
#define LAB1_TRISET_H

#include "Trit.h"

class Unit {
    Trit value_;
    int mostBit_;
    int defaultSize_;
public:
    explicit Unit(int size) {
        value_ = Trit::UNKNOWN;
        mostBit_ = 0;
        defaultSize_ = size;
    }

//    Unit operator& (Unit &unit2);
//    Unit operator~ ();
//    Unit operator| (Unit &unit2);

};

#endif //LAB1_TRISET_H
