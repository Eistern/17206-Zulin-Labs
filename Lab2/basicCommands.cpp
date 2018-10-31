#include "basicCommands.h"
#include "basicCreators.h"
#include "CommandExeptions.h"
#include <cmath>
#include <iostream>
#include <regex>
#include <cfloat>

namespace {
    bool initCommands() noexcept {
        auto *defineCmd = new DefineCreator;
        cmdFactory::getInstance()->registerCommand("DEFINE", defineCmd);

        auto *popCmd = new PopCreator;
        cmdFactory::getInstance()->registerCommand("POP", popCmd);

        auto *pushCmd = new PushCreator;
        cmdFactory::getInstance()->registerCommand("PUSH", pushCmd);

        auto *printCmd = new PrintCreator;
        cmdFactory::getInstance()->registerCommand("PRINT", printCmd);

        auto *addCmd = new AddCreator;
        cmdFactory::getInstance()->registerCommand("+", addCmd);

        auto *subCmd = new SubCreator;
        cmdFactory::getInstance()->registerCommand("-", subCmd);

        auto *mulCmd = new MulCreator;
        cmdFactory::getInstance()->registerCommand("*", mulCmd);

        auto *divCmd = new DivCreator;
        cmdFactory::getInstance()->registerCommand("/", divCmd);

        auto *sqrtCmd = new SqrtCreator;
        cmdFactory::getInstance()->registerCommand("DEFINE", sqrtCmd);
        return true;
    }

    bool isDefined = initCommands(); //NOLINT
}

void CommandDEFINE::execute(Calc::Context *src, const std::list<std::string> &arg) {
    if (arg.size() != 2)
        throw wrong_number_of_arguments();

    double _newDefine = strtod(arg.back().c_str(), nullptr);
    std::string _defineKey = arg.front();

    if (src->isDefined(_defineKey))
        throw already_defined();

    src->addDeifne(_defineKey, _newDefine);
}

void CommandPOP::execute(Calc::Context *src, const std::list<std::string> &arg) {
    if (!arg.empty())
        throw wrong_number_of_arguments();

    src->pop();
}

void CommandPUSH::execute(Calc::Context *src, const std::list<std::string> &arg) {
    if (arg.size() != 1)
        throw wrong_number_of_arguments();

    if (src->isDefined(arg.front()))
        src->push(src->getDefine(arg.front()));
    else {
        std::regex digit("[0-9]*[.]{0,1}[0-9]*");
        if (!std::regex_match(arg.front().begin(), arg.front().end(), digit))
            throw not_defined();

        src->push(strtod(arg.front().c_str(), nullptr));
    }
}

void CommandPRINT::execute(Calc::Context *src, const std::list<std::string> &arg) {
    if (src->stackLength() < 1)
        throw not_enough_elements();

    if (!arg.empty())
        throw wrong_number_of_arguments();

    std::cout << src->peek() << std::endl;
}

void CommandADD::execute(Calc::Context *src, const std::list<std::string> &arg) {
    if (src->stackLength() < 2)
        throw not_enough_elements();

    if (!arg.empty())
        throw wrong_number_of_arguments();

    double arg1 = src->pop();
    double arg2 = src->pop();
    if ((arg1 > 0 && arg2 > 0 && arg1 + arg2 < 0) ||
        (arg1 < 0 && arg2 < 0 && arg1 + arg2 > 0))
        throw double_overflow();
    src->push(arg1 + arg2);
}

void CommandSUB::execute(Calc::Context *src, const std::list<std::string> &arg) {
    if (src->stackLength() < 2)
        throw not_enough_elements();

    if (!arg.empty())
        throw wrong_number_of_arguments();

    double arg1 = src->pop();
    double arg2 = src->pop();
    src->push(arg2 - arg1);
}

void CommandMUL::execute(Calc::Context *src, const std::list<std::string> &arg) {
    if (src->stackLength() < 2)
        throw not_enough_elements();

    if (!arg.empty())
        throw wrong_number_of_arguments();

    double arg1 = src->pop();
    double arg2 = src->pop();
    if (arg1 > DBL_MAX / arg2 || arg1 < DBL_MIN / arg2)
        throw double_overflow();
    src->push(arg1 * arg2);
}

void CommandDIV::execute(Calc::Context *src, const std::list<std::string> &arg) {
    if (src->stackLength() < 2)
        throw not_enough_elements();

    if (!arg.empty())
        throw wrong_number_of_arguments();

    double arg1 = src->pop();
    if (arg1 == 0)
        throw divide_by_zero();

    double arg2 = src->pop();
    src->push(arg2 / arg1);
}

void CommandSQRT::execute(Calc::Context *src, const std::list<std::string> &arg) {
    if (src->stackLength() < 2)
        throw not_enough_elements();

    if (!arg.empty())
        throw wrong_number_of_arguments();

    double arg1 = src->pop();
    if (arg1 < 0)
        throw root_of_negative();

    src->push(sqrt(arg1));
}