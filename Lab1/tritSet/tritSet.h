#ifndef LAB1_TRISET_H
#define LAB1_TRISET_H

#include "Trit.h"
#include <vector>
#include <unordered_map>

using namespace bitOperations;

class tritSet {
    std::vector<unsigned int> _set;
    unsigned int _defaultSize;
public:
    class placeHolder {
        tritSet* _from;
        unsigned int _shift;
    public:
        placeHolder(tritSet* setPointer, unsigned int shear) {
            _from = setPointer;
            _shift = shear;
        }
        //Operator Trit() used to read Trit from index "shift"
        operator Trit() const;// NOLINT
        //Operator = used to set new value on index "shift"
        tritSet& operator=(Trit input);// NOLINT
    };

    //Default constructor for tritSet, witch will initialize vector with 0
    explicit tritSet(unsigned int size) {
        _set = std::vector<unsigned int> (size / 16 + 1);
        _defaultSize = size / 16 + 1;
    }

    //Function shrink changes capacity of tritSet
    // to fit last placed Trit or restore it default size
    void shrink();
    //Function trim erases all elements from lastIndex (sets them to UNKNOWN)
    void trim(size_t lastIndex);
    //Function capacity returns number of allocated bites
    std::size_t capacity() const;
    //Function length returns index of last not unknown Trit + 1
    std::size_t length() const;
    //Function cardinality returns number of contained Trits of type "value" in tritSet, if given
    //Otherwise if returns unordered map, witch contains pairs of <Trit type, number of Trits of this type>
    std::size_t cardinality(Trit value) const;
    std::unordered_map<Trit, int, std::hash<Trit>> cardinality() const;

    //Operator[] creates an object of placeHolder, which could be used to gain access to the element of tritSet
    placeHolder operator[] (unsigned int index);

    //Logic operators overload for tritSet
    tritSet operator& (tritSet &unit2);
    tritSet operator| (tritSet &unit2);
    tritSet operator~ ();
private:
    //This constructor initializes tritSet with given Trit array data
    //Uses in logical operations
    explicit tritSet(std::vector<unsigned int> data) {
        _set = std::move(data);
        _defaultSize = _set.size();
    }

    //Function _resizeSet changes capacity of tritSet to fit "to" number of elements
    void _resizeSet(unsigned int to);
};


#endif //LAB1_TRISET_H
