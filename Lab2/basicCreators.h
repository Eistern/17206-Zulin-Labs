#ifndef LAB2_CREATORS_H
#define LAB2_CREATORS_H

#include "basicCommands.h"

class PushCreator : public CmdCreator {
public:
    Command* create() override {
        return new CommandPUSH;
    }
};

class PopCreator : public CmdCreator {
public:
    Command* create() override {
        return new CommandPOP;
    }
};

class PrintCreator : public CmdCreator {
public:
    Command* create() override {
        return new CommandPRINT;
    }
};

class AddCreator : public CmdCreator {
public:
    Command* create() override {
        return new CommandADD;
    }
};

class SubCreator : public CmdCreator {
public:
    Command* create() override {
        return new CommandSUB;
    }
};

class MulCreator : public CmdCreator {
public:
    Command* create() override {
        return new CommandMUL;
    }
};

class DivCreator : public CmdCreator {
public:
    Command* create() override {
        return new CommandDIV;
    }
};

class SqrtCreator : public CmdCreator {
public:
    Command* create() override {
        return new CommandSQRT;
    }
};

class DefineCreator : public CmdCreator {
public:
    Command* create() override {
        return new CommandDEFINE;
    }
};

#endif //LAB2_CREATORS_H
