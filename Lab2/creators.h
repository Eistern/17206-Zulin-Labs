#ifndef LAB2_CREATORS_H
#define LAB2_CREATORS_H

#include "basicCommands.h"

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

#endif //LAB2_CREATORS_H
