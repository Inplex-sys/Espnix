#include "ChangeDirectoryCommand.h"

#include <FileSystem/Folder.h>
#include <FileSystem/FileSystem.h>
#include <Terminal/Terminal.h>

void ChangeDirectoryCommand::Execute(const std::vector<std::string> &args, Terminal *terminal, FileDescriptor *input, FileDescriptor *output)
{
    if (args.empty())
    {
        return;
    }

    std::string path = args[0];
    FileSystem *fs = FileSystem::GetInstance();

    if (path == ".")
    {
        return;
    }

    if (path == "..")
    {
        if (fs->currentPath != "/")
        {
            fs->currentPath = fs->currentPath.substr(0, fs->currentPath.find_last_of('/'));
            if (fs->currentPath.empty())
                fs->currentPath = "/";
        }
        return;
    }

    std::string newPath = fs->currentPath == "/" ? "/" + path : fs->currentPath + "/" + path;

    if (fs->FolderExists(newPath))
    {
        fs->currentPath = newPath;
    }
    else
    {
        terminal->Write("-esh: cd: " + path + ": No such file or directory\n");
    }
}