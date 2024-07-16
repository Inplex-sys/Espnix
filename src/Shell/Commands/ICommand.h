#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <vector>
#include <string>

class Terminal;

class ICommand
{
public:
    virtual ~ICommand() = default;
    virtual void Execute(const std::vector<std::string> &args, Terminal *terminal) = 0;
};

#endif