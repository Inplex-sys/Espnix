#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <sstream>
#include <vector>

#include <FileSystem/Folder.h>
#include <FileSystem/File.h>
#include <FileSystem/FileSystem.h>
#include <Terminal/Terminal.h>

#include <Shell/Commands/ICommand.h>

#include <Shell/Commands/Busybox/ListCommand.h>
#include <Shell/Commands/Busybox/ChangeDirectoryCommand.h>
#include <Shell/Commands/Busybox/MakeDirectoryCommand.h>
#include <Shell/Commands/Busybox/EchoCommand.h>
#include <Shell/Commands/Busybox/CatCommand.h>
#include <Shell/Commands/Busybox/ClearCommand.h>

#include <Shell/Commands/Other/NmcliCommand.h>

#include "Shell.h"

Shell::Shell() : terminal(nullptr)
{
    commandRegistry["ls"] = std::make_shared<ListCommand>();
    commandRegistry["cd"] = std::make_shared<ChangeDirectoryCommand>();
    commandRegistry["echo"] = std::make_shared<EchoCommand>();
    commandRegistry["mkdir"] = std::make_shared<MakeDirectoryCommand>();
    commandRegistry["cat"] = std::make_shared<CatCommand>();
    commandRegistry["clear"] = std::make_shared<ClearCommand>();

    commandRegistry["nmcli"] = std::make_shared<NmcliCommand>();

    this->prompt = "espnix:/# ";
}

void Shell::Interpret(const std::string &input)
{
    std::istringstream iss(input);
    std::string command;
    std::vector<std::string> args;
    iss >> command;
    std::string arg;
    while (iss >> arg)
    {
        args.push_back(arg);
    }

    terminal->Write(command);
    for (size_t i = 0; i < args.size(); i++)
    {
        terminal->Write(" " + args[i]);
    }

    terminal->Write("\n");

    auto it = commandRegistry.find(command);
    if (it != commandRegistry.end())
    {
        it->second->Execute(args, terminal);
    }
    else
    {
        terminal->Write(command + ": command not found\n");
    }

    FileSystem *fs = FileSystem::GetInstance();

    this->prompt = "espnix:" + fs->currentPath + "# ";
    this->Prompt();
}

void Shell::Prompt()
{
    terminal->Write(prompt);
}