#ifndef LAB1_TRIT_H
#define LAB1_TRIT_H

enum class Trit : unsigned int {
    FALSE = 0b10, UNKNOWN = 0b0, TRUE = 0b01
};

//Logic operators overload for single Trit
Trit operator& (const Trit& trit1, const Trit& trit2);
Trit operator| (const Trit& trit1, const Trit& trit2);
Trit operator~ (const Trit& trit);

#endif //LAB1_TRIT_H
