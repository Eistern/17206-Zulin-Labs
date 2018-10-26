#ifndef LAB2_CMDFACTORY_H
#define LAB2_CMDFACTORY_H

#include "Calc.h"
#include <list>

class Command {
public:
    virtual void execute(Calc::Context *src, const std::list<std::string> &arg) = 0;
};

class CmdCreator {
public:
    virtual Command* create() {};
};

class cmdFactory {
    cmdFactory() = default;
    std::map<std::string, CmdCreator*> _creatorArray;
public:
    cmdFactory(const cmdFactory &old) = delete;
    static cmdFactory* getInstance() {
        static cmdFactory _factory;
        return &_factory;
    }
    void registerCommand(const std::string& key, CmdCreator* creator) {
        _creatorArray[key] = creator;
    }
    Command* getCommand(const std::string& cmdName) {
        return _creatorArray.at(cmdName)->create();
    }
    ~cmdFactory() noexcept {
        for (auto it : _creatorArray) {
            delete (it.second);
            it.second = nullptr;
        }
    }
};


#endif //LAB2_CMDFACTORY_H
