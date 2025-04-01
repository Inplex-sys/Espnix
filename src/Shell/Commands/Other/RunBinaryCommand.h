#ifndef RUN_BINARY_COMMAND_H
#define RUN_BINARY_COMMAND_H

#include <vector>
#include <string>
#include <Shell/Commands/ICommand.h>

class Terminal;
class FileDescriptor;
class Loader;

class RunBinaryCommand : public ICommand
{
private:
    Loader *loader;

public:
    RunBinaryCommand(Loader *sysLoader);
    void Execute(const std::vector<std::string> &args, Terminal *terminal, FileDescriptor *input, FileDescriptor *output) override;
};

#endif