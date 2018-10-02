#include "Trit.h"

Trit operator&(const Trit& trit1, const Trit& trit2) {
    if (trit1 == Trit::FALSE || trit2 == Trit::FALSE)
        return Trit::FALSE;

    if (trit1 == Trit::UNKNOWN || trit2 == Trit::UNKNOWN)
        return Trit::UNKNOWN;

    return Trit::TRUE;
}

Trit operator|(const Trit& trit1, const Trit& trit2) {
    if (trit1 == Trit::TRUE || trit2 == Trit::TRUE)
        return Trit::TRUE;

    if (trit1 == Trit::UNKNOWN || trit2 == Trit::UNKNOWN)
        return Trit::UNKNOWN;

    return Trit::FALSE;
}

Trit operator~(const Trit& trit) {
    if (trit == Trit::FALSE)
        return Trit::TRUE;

    if (trit == Trit::TRUE)
        return Trit::FALSE;

    return Trit::UNKNOWN;
}

void bitOperations::setTrit(unsigned int &to, unsigned int pos, Trit value) {
    //Replace the changing trit with 0b11
    to = to & ~((unsigned)3 << (2 * pos));
    //Set the trit into position
    to = to | (static_cast<unsigned int>(value) << (2 * pos));
}

Trit bitOperations::getTrit(unsigned int from, unsigned int pos){
    unsigned int value = (from >> (pos * 2)) % 4;
    return static_cast<Trit>(value);
}