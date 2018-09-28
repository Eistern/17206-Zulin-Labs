#include <iostream>
#include "tritSet.h"

int main() {
    tritSet test(10);
    (test[0]) = Trit::UNKNOWN;
    test[1] = Trit::TRUE;
    tritSet test2(5);
    test2[2] = Trit::FALSE;
    test2[1] = Trit::FALSE;
    tritSet test3 = test & test2;
    bool K = (test3[1] == Trit::FALSE);
    Trit a = test[1];
    bool b = (test[0] == Trit::UNKNOWN);
    unsigned int d =  test.cardinality(Trit::TRUE);
    return 0;
}