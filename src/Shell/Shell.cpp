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

#include <Shell/Busybox/ListCommand.h>
#include <Shell/Busybox/ChangeDirectoryCommand.h>
#include <Shell/Busybox/MakeDirectoryCommand.h>
#include <Shell/Busybox/EchoCommand.h>

#include "Shell.h"
#include "ICommand.h"

Shell::Shell() : terminal(nullptr)
{
    commandRegistry["ls"] = std::make_shared<ListCommand>();
    commandRegistry["cd"] = std::make_shared<ChangeDirectoryCommand>();
    commandRegistry["echo"] = std::make_shared<EchoCommand>();
    commandRegistry["mkdir"] = std::make_shared<MakeDirectoryCommand>();
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