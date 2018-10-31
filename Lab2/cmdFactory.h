#ifndef LAB2_CMDFACTORY_H
#define LAB2_CMDFACTORY_H

#include "basicInterface.h"

class command_not_found : public std::exception {
public:
    const char* what() const noexcept override {
        return "Command not found";
    }
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
        if (_creatorArray.find(cmdName) == _creatorArray.end())
            throw command_not_found();
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
