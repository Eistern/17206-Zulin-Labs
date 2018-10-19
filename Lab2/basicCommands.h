#ifndef LAB2_BASICCOMMANDS_H
#define LAB2_BASICCOMMANDS_H

#include "Calc.h"

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

#endif //LAB2_BASICCOMMANDS_H
