#include <FileSystem/Folder.h>
#include <FileSystem/file.h>

#include "FileSystem.h"

FileSystem* FileSystem::instance = nullptr;

FileSystem::FileSystem()
{
    this->root = new Folder();
    this->currentPath = "/";
}

Folder *FileSystem::GetFolder(std::string path)
{
    Folder *current = this->root;

    std::string delimiter = "/";
    size_t pos = 0;
    std::string token;

    while ((pos = path.find(delimiter)) != std::string::npos)
    {
        token = path.substr(0, pos);

        for (auto &folder : current->folders)
        {
            if (folder.foldername == token)
            {
                current = &folder;
                break;
            }
        }

        path.erase(0, pos + delimiter.length());
    }

    return current;
}

File *FileSystem::GetFile(std::string path)
{
    Folder *folder = this->GetFolder(path);

    for (auto &file : folder->files)
    {
        if (file.filename == path)
        {
            return &file;
        }
    }

    return nullptr;
}

FileSystem *FileSystem::GetInstance() {
    if (instance == nullptr) {
        instance = new FileSystem();
    }
    return instance;
}