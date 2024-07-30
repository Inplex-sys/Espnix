#include "EchoCommand.h"

#include <FileSystem/Folder.h>
#include <FileSystem/File.h>
#include <FileSystem/FileSystem.h>
#include <Terminal/Terminal.h>

void EchoCommand::Execute(const std::vector<std::string> &args, Terminal *terminal, FileDescriptor *input, FileDescriptor *output)
{
    for (size_t i = 0; i < args.size(); i++)
    {
        terminal->Write(args[i] + " ");
    }

    terminal->Write("\n");
}