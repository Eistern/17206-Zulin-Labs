#include "triSet.h"

Unit Unit::operator&(Unit &unit2) {
    if (this->value_ == Trit::FALSE || unit2.value_ == Trit::FALSE)
        return Unit(Trit::FALSE);

    if (this->value_ == Trit::UNKNOWN || unit2.value_ == Trit::UNKNOWN)
        return Unit(Trit::UNKNOWN);

    return Unit(Trit::TRUE);
}

Unit Unit::operator|(Unit &unit2) {
    if (this->value_ == Trit::TRUE || unit2.value_ == Trit::TRUE)
        return Unit(Trit::TRUE);

    if (this->value_ == Trit::UNKNOWN || unit2.value_ == Trit::UNKNOWN)
        return Unit(Trit::UNKNOWN);

    return Unit(Trit::FALSE);
}

Unit Unit::operator~() {
    return Unit(static_cast<Trit>(static_cast<int>(this->value_) * -1));
}