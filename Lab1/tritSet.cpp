#include <stdexcept>
#include "tritSet.h"

std::size_t tritSet::length() {
    unsigned int index = this->set.size() * 16 - 1;
    while (getTrit(this->set[index / 16], index % 16) == Trit::UNKNOWN)
        --index;
    ++index;
    return index;
}

std::size_t tritSet::cardinality(Trit value) {
    std::size_t result = 0;
    unsigned int to = this->length();
    for (unsigned int i = 0; i < to; ++i)
        if (getTrit(this->set[i / 16], i % 16) == value)
            result++;

    return result;
}

//unordered_map<Trit, int, std::hash<int>> tritSet::cardinality() {
//    unordered_map<Trit, int, std::hash<int>> result;
//    result.emplace(Trit::FALSE, this->cardinality(Trit::FALSE));
//    result.emplace(Trit::UNKNOWN, this->cardinality(Trit::UNKNOWN));
//    result.emplace(Trit::TRUE, this->cardinality(Trit::TRUE));
//
//    return result;
//}

tritSet::placeHolder tritSet::operator[] (unsigned int index) {
    return {this, index};
}

tritSet tritSet::operator& (tritSet &unit2) {
    unsigned int max = this->set.size() > unit2.set.size() ? this->set.size() : unit2.set.size();
    unsigned int min = this->set.size() > unit2.set.size() ? unit2.set.size() : this->set.size();
    std::vector<unsigned int> _new(max);
    Trit left, right;
    Trit null = Trit::UNKNOWN;
    unsigned int i;
    for (i = 0; i < min * 16; ++i) {
        left = getTrit(this->set[i / 16], i % 16);
        right = getTrit(unit2.set[i / 16], i % 16);
        setTrit(_new[i / 16], i % 16, left & right);
    }
    std::vector<unsigned int> maxV = unit2.set.size() == max ? unit2.set : this->set;
    for (i; i < max * 16; ++i) {
        left = getTrit(maxV[i / 16], i % 16);
        setTrit(_new[i / 16], i % 16, left & null);
    }
    return tritSet(_new);
}

tritSet tritSet::operator| (tritSet &unit2) {
    unsigned int max = this->set.size() > unit2.set.size() ? this->set.size() : unit2.set.size();
    unsigned int min = this->set.size() > unit2.set.size() ? unit2.set.size() : this->set.size();
    std::vector<unsigned int> _new(max);
    Trit left, right;
    Trit null = Trit::UNKNOWN;
    unsigned int i;
    for (i = 0; i < min * 16; ++i) {
        left = getTrit(this->set[i / 16], i % 16);
        right = getTrit(unit2.set[i / 16], i % 16);
        setTrit(_new[i / 16], i % 16, left | right);
    }
    std::vector<unsigned int> maxV = unit2.set.size() == max ? unit2.set : this->set;
    for (i; i < max * 16; ++i) {
        left = getTrit(maxV[i / 16], i % 16);
        setTrit(_new[i / 16], i % 16, left | null);
    }
    return tritSet(_new);
}

tritSet tritSet::operator~ () {
    std::vector<unsigned int> _new(this->set.size());
    Trit buff;
    unsigned int i;
    for (i = 0; i < this->set.size() * 16; ++i) {
        buff = getTrit(this->set[i / 16], i % 16);
        setTrit(_new[i / 16], i % 16, ~buff);
    }
    return tritSet(_new);
}

tritSet::placeHolder::operator Trit() const{
    return getTrit(from_->set[shift_ / 16], shift_ % 16);
}

tritSet& tritSet::placeHolder::operator=(Trit input) {
    setTrit(from_->set[shift_ / 16], shift_ % 16, input);
    return *from_;
}