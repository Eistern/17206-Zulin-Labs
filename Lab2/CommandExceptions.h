#ifndef LAB2_COMMANDEXEPTIONS_H
#define LAB2_COMMANDEXEPTIONS_H

#include <exception>

class CommandExceptions : public std::exception {
public:
    const char* what() const noexcept override = 0;
};

class wrong_number_of_arguments : public CommandExceptions {
public:
    const char* what() const noexcept override {
        return "Wrong number of arguments";
    }
};

class not_enough_elements : public CommandExceptions {
public:
    const char* what() const noexcept override {
        return "Not enough elements in stack";
    }
};

class divide_by_zero : public CommandExceptions {
public:
    const char* what() const noexcept override {
        return "Division by zero";
    }
};

class root_of_negative : public CommandExceptions {
public:
    const char* what() const noexcept override {
        return "Square root of negative";
    }
};

class double_overflow : public CommandExceptions {
public:
    const char* what() const noexcept override {
        return "Double overflow";
    }
};

class not_defined : public  CommandExceptions {
public:
    const char* what() const noexcept override {
        return "Value is not defined";
    }
};

class already_defined : public CommandExceptions {
public:
    const char* what() const noexcept override {
        return "Value already defined";
    }
};

#endif //LAB2_COMMANDEXEPTIONS_H
