#ifndef LAB1_TRIT_H
#define LAB1_TRIT_H

enum class Trit : unsigned int {
    FALSE = 0b10, UNKNOWN = 0b0, TRUE = 0b01
};

Trit operator& (Trit &trit1, Trit &trit2);

Trit operator| (Trit &trit1, Trit &trit2);

Trit operator~ (Trit &trit);

namespace bitOperations {
    void setTrit (unsigned int &to, unsigned int pos, Trit value);
    Trit getTrit (unsigned int from, unsigned int pos);
}

#endif //LAB1_TRIT_H
