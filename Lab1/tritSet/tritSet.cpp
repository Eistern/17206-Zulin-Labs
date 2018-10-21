#include "tritSet.h"

tritSet::placeHolder tritSet::operator[] (unsigned int index) {
    return {this, index};
}

Trit tritSet::operator[](unsigned int index) const {
    if (index >= this->length())
        return Trit::UNKNOWN;
    return getTrit(this->_set[index / (sizeof(size_t) * 4)], index % (sizeof(size_t) * 4));
}

tritSet tritSet::operator& (tritSet &unit2) {
    unsigned int max = this->_set.size() > unit2._set.size() ? this->_set.size() : unit2._set.size();
    unsigned int min = this->_set.size() > unit2._set.size() ? unit2._set.size() : this->_set.size();
    std::vector<unsigned int> _new(max);
    Trit left, right;
    Trit null = Trit::UNKNOWN;
    unsigned int i;
    for (i = 0; i < min * (sizeof(size_t) * 4); ++i) {
        left = getTrit(this->_set[i / (sizeof(size_t) * 4)], i % (sizeof(size_t) * 4));
        right = getTrit(unit2._set[i / (sizeof(size_t) * 4)], i % (sizeof(size_t) * 4));
        setTrit(_new[i / (sizeof(size_t) * 4)], i % (sizeof(size_t) * 4), left & right);
    }
    std::vector<unsigned int> maxV = unit2._set.size() == max ? unit2._set : this->_set;
    for (i; i < max * (sizeof(size_t) * 4); ++i) {
        left = getTrit(maxV[i / (sizeof(size_t) * 4)], i % (sizeof(size_t) * 4));
        setTrit(_new[i / (sizeof(size_t) * 4)], i % (sizeof(size_t) * 4), left & null);
    }
    return tritSet(_new);
}

tritSet tritSet::operator| (tritSet &unit2) {
    unsigned int max = this->_set.size() > unit2._set.size() ? this->_set.size() : unit2._set.size();
    unsigned int min = this->_set.size() > unit2._set.size() ? unit2._set.size() : this->_set.size();
    std::vector<unsigned int> _new(max);
    Trit left, right;
    Trit null = Trit::UNKNOWN;
    unsigned int i;
    for (i = 0; i < min * (sizeof(size_t) * 4); ++i) {
        left = getTrit(this->_set[i / (sizeof(size_t) * 4)], i % (sizeof(size_t) * 4));
        right = getTrit(unit2._set[i / (sizeof(size_t) * 4)], i % (sizeof(size_t) * 4));
        setTrit(_new[i / (sizeof(size_t) * 4)], i % (sizeof(size_t) * 4), left | right);
    }
    std::vector<unsigned int> maxV = unit2._set.size() == max ? unit2._set : this->_set;
    for (i; i < max * (sizeof(size_t) * 4); ++i) {
        left = getTrit(maxV[i / (sizeof(size_t) * 4)], i % (sizeof(size_t) * 4));
        setTrit(_new[i / (sizeof(size_t) * 4)], i % (sizeof(size_t) * 4), left | null);
    }
    return tritSet(_new);
}

tritSet tritSet::operator~ () {
    std::vector<unsigned int> _new(this->_set.size());
    Trit buff;
    unsigned int i;
    for (i = 0; i < this->_set.size() * (sizeof(size_t) * 4); ++i) {
        buff = getTrit(this->_set[i / (sizeof(size_t) * 4)], i % (sizeof(size_t) * 4));
        setTrit(_new[i / (sizeof(size_t) * 4)], i % (sizeof(size_t) * 4), ~buff);
    }
    return tritSet(_new);
}

tritSet::placeHolder::operator Trit() const{
    if (_shift > _from->length())
        return Trit::UNKNOWN;
    return getTrit(_from->_set[_shift / (sizeof(size_t) * 4)], _shift % (sizeof(size_t) * 4));
}

tritSet& tritSet::placeHolder::operator=(Trit input) { // NOLINT
    if (input == Trit::UNKNOWN && _shift > _from->length())
        return *_from;

    if (_shift > _from->length())
        _from->_resizeSet(_shift);
    setTrit(_from->_set[_shift / (sizeof(size_t) * 4)], _shift % (sizeof(size_t) * 4), input);
    return *_from;
}

std::size_t tritSet::capacity() const{
    return _set.size();
}

void tritSet::_resizeSet(unsigned int to) {
    this->_set.resize(to / (sizeof(size_t) * 4) + 1);
}

void tritSet::shrink() {
    this->_resizeSet(length() - 1 > _defaultSize * (sizeof(size_t) * 4) - 1 ? length() - 1 : _defaultSize * (sizeof(size_t) * 4) - 1);
}

void tritSet::trim(size_t lastIndex) {
    if (lastIndex < (lastIndex / sizeof(size_t) + 1) * sizeof(size_t)) {
        for (int i = lastIndex; i < (lastIndex / sizeof(size_t) + 1) * sizeof(size_t); i++)
            (*this)[i] = Trit::UNKNOWN;
    }
    this->_resizeSet(lastIndex);
}

std::size_t tritSet::length() const{
    unsigned int index = this->_set.size() * (sizeof(size_t) * 4) - 1;
    while (getTrit(this->_set[index / (sizeof(size_t) * 4)], index % (sizeof(size_t) * 4)) == Trit::UNKNOWN && index != 0)
        --index;
    ++index;
    return index;
}

std::size_t tritSet::cardinality(Trit value) const{
    std::size_t result = 0;
    unsigned int to = this->length();
    for (unsigned int i = 0; i < to; ++i)
        if (getTrit(this->_set[i / (sizeof(size_t) * 4)], i % (sizeof(size_t) * 4)) == value)
            result++;

    return result;
}

std::unordered_map<Trit, int, std::hash<Trit>> tritSet::cardinality() const{
    std::unordered_map<Trit, int, std::hash<Trit>> result{};
    result.emplace(Trit::FALSE, this->cardinality(Trit::FALSE));
    result.emplace(Trit::UNKNOWN, this->cardinality(Trit::UNKNOWN));
    result.emplace(Trit::TRUE, this->cardinality(Trit::TRUE));

    return result;
}

void tritSet::setTrit(unsigned int &to, unsigned int pos, Trit value) {
    //Replace the changing trit with 0b11
    to = to & ~((unsigned)3 << (2 * pos));
    //Set the trit into position
    to = to | (static_cast<unsigned int>(value) << (2 * pos));
}

Trit tritSet::getTrit(unsigned int from, unsigned int pos) {
    unsigned int value = (from >> (pos * 2)) % 4;
    return static_cast<Trit>(value);
}