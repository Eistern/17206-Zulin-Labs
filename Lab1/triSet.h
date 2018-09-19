#ifndef LAB1_TRISET_H
#define LAB1_TRISET_H

enum class Trit : int {
    FALSE = -1, UNKNOWN = 0, TRUE = 1
};

class Unit {
    Trit value_;
public:
    explicit Unit(Trit trit) {
        value_ = trit;
    }

    Unit operator& (Unit &unit2);
    Unit operator~ ();
    Unit operator| (Unit &unit2);

};


#endif //LAB1_TRISET_H
