#include "Trit.h"

Trit operator&(Trit &trit1, Trit &trit2) {
    if (trit1 == Trit::FALSE || trit2 == Trit::FALSE)
        return Trit::FALSE;

    if (trit1 == Trit::UNKNOWN || trit2 == Trit::UNKNOWN)
        return Trit::UNKNOWN;

    return Trit::TRUE;
}

Trit operator|(Trit &trit1, Trit &trit2) {
    if (trit1 == Trit::TRUE || trit2 == Trit::TRUE)
        return Trit::TRUE;

    if (trit1 == Trit::UNKNOWN || trit2 == Trit::UNKNOWN)
        return Trit::UNKNOWN;

    return Trit::FALSE;
}

Trit operator~(Trit &trit) {
    return static_cast<Trit>(static_cast<int>(trit) * -1);
}

Trit &operator++(Trit &trit) {
    trit = static_cast<Trit>(static_cast<int>(trit) + 1);
    if (trit == Trit::TRUE)
        trit = static_cast<Trit>(static_cast<int>(trit) - 1);

    return trit;
};