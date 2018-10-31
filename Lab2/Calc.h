#ifndef LAB2_CALC_H
#define LAB2_CALC_H

#include <stack>
#include <map>

class Calc {
public:
    class Context {
        friend class Calc;
        std::stack<double> _activeStack;
        std::map<std::string, double> _definedValues;

        Context() = default;
    public:
        bool isDefined(const std::string &key) const;
        double getDefine(const std::string &key) const;
        void addDefine(const std::string &key, double value);
        unsigned long long int stackLength() const;
        void push(double _new);
        double pop();
        double peek() const;
    };
    void run(std::istream& fin, std::ostream& fout);
};

#endif //LAB2_CALC_H
