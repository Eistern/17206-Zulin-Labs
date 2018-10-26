#ifndef LAB2_BASICCOMMANDS_H
#define LAB2_BASICCOMMANDS_H

#include "Calc.h"
#include "cmdFactory.h"
#include <list>

class CommandDEFINE : public Command {
public:
    void execute(Calc::Context *src, const std::list<std::string> &arg) override;
};

class CommandPOP : public Command {
public:
    void execute(Calc::Context *src, const std::list<std::string> &arg) override;
};

class CommandPUSH : public Command {
public:
    void execute(Calc::Context *src, const std::list<std::string> &arg) override;
};

class CommandPRINT : public Command {
    void execute(Calc::Context *src, const std::list<std::string> &arg) override;
};

class CommandADD : public Command {
public:
    void execute(Calc::Context *src, const std::list<std::string> &arg) override;
};

class CommandSUB : public Command {
public:
    void execute(Calc::Context *src, const std::list<std::string> &arg) override;
};

class CommandMUL : public Command {
public:
    void execute(Calc::Context *src, const std::list<std::string> &arg) override;
};

class CommandDIV : public Command {
public:
    void execute(Calc::Context *src, const std::list<std::string> &arg) override;
};

class CommandSQRT : public Command {
public:
    void execute(Calc::Context *src, const std::list<std::string> &arg) override;
};

#endif //LAB2_BASICCOMMANDS_H
