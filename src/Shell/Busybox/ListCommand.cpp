#include "ListCommand.h"

#include <FileSystem/Folder.h>
#include <FileSystem/File.h>
#include <FileSystem/FileSystem.h>
#include <Terminal/Terminal.h>

void ListCommand::Execute(const std::vector<std::string> &args, Terminal *terminal){
    if (args.size() == 0)
    {
        FileSystem *fs = FileSystem::GetInstance();
        Folder *folder = fs->GetFolder(fs->currentPath);
        for (auto &file : folder->files)
        {
            terminal->Write(file.filename + " ");
        }
        
        for (auto &folder : folder->folders)
        {
            terminal->Write(folder.foldername + " ");
        }
        return;
    }
    terminal->Write("Executing 'ls' command\n");
}