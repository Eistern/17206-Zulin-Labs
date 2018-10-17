#ifndef LAB2_CALC_H
#define LAB2_CALC_H


#include <stack>
#include <map>

class Calc {
    std::stack<int> _activeStack = {};
    std::map<std::string, int> _definedValues = {};
public:
    void run(const std::istream& fin, const std::ostream& fout);
    int getDefine(const std::string& key) const;
    void addDeifne(const std::string& key, int value);
    unsigned int stackLength() const;
    void push(int _new);
    int pop();
};


#endif //LAB2_CALC_H
