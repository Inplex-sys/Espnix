#ifndef LIST_COMMAND_H
#define LIST_COMMAND_H

#include <vector>
#include <string>

#include <Shell/ICommand.h>

class File;
class Terminal;

class ListCommand : public ICommand
{
public:
    void Execute(const std::vector<std::string> &args, Terminal *terminal) override;
};

#endif