#ifndef LAB1_TRISET_H
#define LAB1_TRISET_H

#include "Trit.h"
#include <vector>

using namespace bitOperations;

class tritSet {
    std::vector<unsigned int> set;
    Trit operatingTrit_;
    unsigned int defaultSize_;
public:
    explicit tritSet(unsigned int size) {
        set = std::vector<unsigned int> (size);
        defaultSize_ = size;
        operatingTrit_ = Trit::UNKNOWN;
    }

    unsigned int capacity() {
        return sizeof(*this) * 8;
    }

    tritSet operator[] (unsigned int index);
    tritSet& operator= (Trit value);
    bool operator== (Trit value);
    tritSet operator& (tritSet &unit2);
    tritSet operator| (tritSet &unit2);
    tritSet operator~ ();
private:
    explicit tritSet(std::vector<unsigned int> data) {
        set = std::move(data);
        defaultSize_ = set.size();
        operatingTrit_ = Trit::UNKNOWN;
    }
    unsigned int findOperatingIndex();
};


#endif //LAB1_TRISET_H
