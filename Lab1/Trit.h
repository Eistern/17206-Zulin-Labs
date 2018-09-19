#ifndef LAB1_TRIT_H
#define LAB1_TRIT_H

enum class Trit : int {
    FALSE = -1, UNKNOWN = 0, TRUE = 1
};

Trit operator& (Trit &trit1, Trit &trit2);

Trit operator| (Trit &trit1, Trit &trit2);

Trit operator~ (Trit &trit);

Trit& operator++ (Trit &trit);

#endif //LAB1_TRIT_H
