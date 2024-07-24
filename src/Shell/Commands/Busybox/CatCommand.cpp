#include <sstream>
#include <string.h>

#include <FileSystem/Folder.h>
#include <FileSystem/File.h>
#include <FileSystem/FileSystem.h>
#include <Terminal/Terminal.h>

#include "CatCommand.h"

void CatCommand::Execute(const std::vector<std::string> &args, Terminal *terminal)
{
    if (args.size() != 1)
    {
        terminal->Write("Usage: cat <filename>\n");
        return;
    }

    FileSystem *fs = FileSystem::GetInstance();

    std::string filePath = args[0];
    File *file = fs->GetFile(filePath);
    if (file == nullptr)
    {
        terminal->Write("cat: " + filePath + ": No such file or directory\n");
        return;
    }

    terminal->Write(file->Read());
}