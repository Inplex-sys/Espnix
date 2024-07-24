#include <set>
#include <string>

#include <FileSystem/Folder.h>
#include <FileSystem/File.h>
#include <FileSystem/FileSystem.h>

#include <Terminal/Terminal.h>

#include <Utils/Utils.h>

#include "ListCommand.h"

void ListCommand::Execute(const std::vector<std::string> &args, Terminal *terminal)
{
    std::set<std::string> flags(args.begin(), args.end());

    FileSystem *fs = FileSystem::GetInstance();
    Folder *folder = fs->GetFolder(fs->currentPath);

    if (flags.find("-a") != flags.end() || flags.find("--all") != flags.end())
    {
        for (Folder *subFolder : folder->folders)
        {
            terminal->Write(subFolder->name + " ");
        }

        for (File *file : folder->files)
        {
            terminal->Write(file->name + " ");
        }

        terminal->Write("\n");
        return;
    }
    else if (flags.find("-l") != flags.end())
    {
        for (Folder *subFolder : folder->folders)
        {
            std::string permissions = fs->GetStringPermissions(subFolder->permissions, "folder");
            terminal->Write(permissions + " root root 4096 " + Utils::FormatDate(subFolder->creationDate) + " " + subFolder->name + "\n");
        }

        for (File *file : folder->files)
        {
            std::string permissions = fs->GetStringPermissions(file->permissions, "file");
            terminal->Write(permissions + " root root " + std::to_string(file->size) + " " + Utils::FormatDate(file->creationDate) + " " + file->name + "\n");
        }
        return;
    }
    else
    {
        for (Folder *subFolder : folder->folders)
        {
            terminal->Write(subFolder->name + " ");
        }

        for (File *file : folder->files)
        {
            terminal->Write(file->name + " ");
        }

        terminal->Write("\n");
        return;
    }
}