#include "ChangeDirectoryCommand.h"

#include <FileSystem/Folder.h>
#include <FileSystem/FileSystem.h>
#include <Terminal/Terminal.h>

void ChangeDirectoryCommand::Execute(const std::vector<std::string> &args, Terminal *terminal)
{
    std::string path = args[0];

    FileSystem *fs = FileSystem::GetInstance();
    Folder *folder = fs->GetFolder(fs->currentPath);

    if (path == ".")
    {
        return;
    }

    if (path == "..")
    {
        if (fs->currentPath == "/")
        {
            return;
        }

        fs->currentPath = fs->currentPath.substr(0, fs->currentPath.find_last_of("/"));
        return;
    }

    for (Folder *subFolder : folder->folders)
    {
        if (subFolder->name == path)
        {
            if (fs->currentPath == "/")
            {
                fs->currentPath += path;
            }
            else
            {
                fs->currentPath += "/" + path;
            }
        }

        return;
    }

    terminal->Write("-esh: cd: " + args[0] + ": No such file or directory\n");
}