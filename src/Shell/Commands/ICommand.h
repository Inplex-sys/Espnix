#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <vector>
#include <string>

class Terminal;
class FileDescriptor;

class ICommand
{
public:
    virtual ~ICommand() = default;
    virtual void Execute(const std::vector<std::string> &args, Terminal *terminal, FileDescriptor *input, FileDescriptor *output) = 0;
};

#endif