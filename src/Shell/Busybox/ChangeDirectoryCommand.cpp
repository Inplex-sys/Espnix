#include "ChangeDirectoryCommand.h"

#include <FileSystem/Folder.h>
#include <FileSystem/FileSystem.h>
#include <Terminal/Terminal.h>

void ChangeDirectoryCommand::Execute(const std::vector<std::string> &args, Terminal *terminal)
{
    if (args.size() == 0)
    {
        terminal->Write("cd: missing argument\n");
        return;
    }

    /* FileSystem *fs = FileSystem::GetInstance();
    Folder *folder = fs->GetFolder(fs->currentPath);

    if (args[0] == "..")
    {
        if (folder->parent != nullptr)
        {
            fs->currentPath = folder->parent->path;
        }
        return;
    }

    for (auto &f : folder->folders)
    {
        if (f.foldername == args[0])
        {
            fs->currentPath = f.path;
            return;
        }
    } */

    terminal->Write("cd: no such file or directory: " + args[0] + "\n");
}