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

class command {
public:
    virtual void execute(Calc *src, std::list<std::string> arg) = 0;
};

class commandDEFINE : public command {
public:
    void execute(Calc *src, std::list<std::string> arg) override;
};

class commandPOP : public command {
public:
    void execute(Calc *src, std::list<std::string> arg) override;
};

class commandPUSH : public command {
public:
    void execute(Calc *src, std::list<std::string> arg) override;
};

class commandADD : public command {
public:
    void execute(Calc *src, std::list<std::string> arg) override;
};

class commandSUB : public command {
public:
    void execute(Calc *src, std::list<std::string> arg) override;
};

class commandMUL : public command {
public:
    void execute(Calc *src, std::list<std::string> arg) override;
};

class commandDIV : public command {
public:
    void execute(Calc *src, std::list<std::string> arg) override;
};

class commandSQRT : public command {
public:
    void execute(Calc *src, std::list<std::string> arg) override;
};

class cmdCreator {
    static const std::map<std::string, cmdCreator*> _creatorArray;
public:
    command* factoryMethod(const std::string& type) {
        return _creatorArray.at(type)->create();
    }
    virtual command* create() {};
};

class pushCreator : public cmdCreator {
public:
    command* create() override {
        return new commandPUSH;
    }
};

class popCreator : public cmdCreator {
public:
    command* create() override {
        return new commandPOP;
    }
};

class addCreator : public cmdCreator {
public:
    command* create() override {
        return new commandADD;
    }
};

class subCreator : public cmdCreator {
public:
    command* create() override {
        return new commandSUB;
    }
};

class mulCreator : public cmdCreator {
public:
    command* create() override {
        return new commandMUL;
    }
};

class divCreator : public cmdCreator {
public:
    command* create() override {
        return new commandDIV;
    }
};

class sqrtCreator : public cmdCreator {
public:
    command* create() override {
        return new commandSQRT;
    }
};

class defineCreator : public cmdCreator {
public:
    command* create() override {
        return new commandDEFINE;
    }
};

#endif //LAB2_CALC_H
