#ifndef LAB1_TRISET_H
#define LAB1_TRISET_H

#include "Trit.h"
#include <vector>
#include <unordered_map>

using namespace bitOperations;

class tritSet {
    std::vector<unsigned int> set;
    Trit operatingTrit_;
    unsigned int defaultSize_;
public:
    class placeHolder {
        tritSet* from_;
        unsigned int shift_;
    public:
        placeHolder(tritSet* setPointer, unsigned int shear) {
            from_ = setPointer;
            shift_ = shear;
        }
        operator Trit() const;
        tritSet& operator=(Trit input);
    };

    explicit tritSet(unsigned int size) {
        set = std::vector<unsigned int> (size / 16 + 1);
        defaultSize_ = size / 16 + 1;
        operatingTrit_ = Trit::UNKNOWN;
    }

    unsigned int capacity() {
        return sizeof(*this) * 8;
    }

    std::size_t length();
    std::size_t cardinality(Trit value);
//    unordered_map<Trit, int, std::hash<int>> cardinality();

    placeHolder operator[] (unsigned int index);
    tritSet operator& (tritSet &unit2);
    tritSet operator| (tritSet &unit2);
    tritSet operator~ ();
private:
    explicit tritSet(std::vector<unsigned int> data) {
        set = std::move(data);
        defaultSize_ = set.size();
        operatingTrit_ = Trit::UNKNOWN;
    }
};


#endif //LAB1_TRISET_H
