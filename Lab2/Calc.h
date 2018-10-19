#ifndef LAB2_CALC_H
#define LAB2_CALC_H

#include <cstdlib>
#include <cmath>
#include <stack>
#include <map>
#include <list>


class Calc {
    std::stack<double> _activeStack;
    std::map<std::string, double> _definedValues;
public:
    void run(const std::istream& fin, const std::ostream& fout);
    bool isDefined(const std::string &key) const;
    double getDefine(const std::string &key) const;
    void addDeifne(const std::string &key, double value);
    unsigned int stackLength() const;
    void push(double _new);
    double pop();
    double peek();
};

#endif //LAB2_CALC_H
