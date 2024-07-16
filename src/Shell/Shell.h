#ifndef SHELL_H
#define SHELL_H

#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <memory>
#include <vector>
#include <iostream>

class ICommand;
class Terminal;

class Shell
{
private:
    std::map<std::string, std::shared_ptr<ICommand>> commandRegistry;
    std::string prompt;

public:
    Terminal *terminal;

    Shell();
    void Interpret(const std::string &input);
    void Prompt();
};

#endif
