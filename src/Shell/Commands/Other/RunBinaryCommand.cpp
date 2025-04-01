#include "RunBinaryCommand.h"
#include <Terminal/Terminal.h>
#include <System/Loader.h>

RunBinaryCommand::RunBinaryCommand(Loader *sysLoader) : loader(sysLoader)
{
}

void RunBinaryCommand::Execute(const std::vector<std::string> &args, Terminal *terminal, FileDescriptor *input, FileDescriptor *output)
{
    if (args.size() < 1)
    {
        terminal->Write("Usage: run <binary_path>\n");
        return;
    }

    std::string path = args[0];
    if (!path.empty() && path[0] != '/')
    {
        path = "/bin/" + path;
    }

    if (!loader)
    {
        terminal->Write("Error: System loader not initialized\n");
        return;
    }

    loader->LoadAndExecute(path);
}