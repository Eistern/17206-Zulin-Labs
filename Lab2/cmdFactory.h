#ifndef LAB2_CMDFACTORY_H
#define LAB2_CMDFACTORY_H

#include "basicInterface.h"

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
