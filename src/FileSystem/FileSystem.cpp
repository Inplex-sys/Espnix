#include <FileSystem/Folder.h>
#include <FileSystem/file.h>

#include "FileSystem.h"

FileSystem *FileSystem::instance = nullptr;

FileSystem::FileSystem()
{
    this->root = new Folder();
    this->currentPath = "/";
}

std::string FileSystem::GetStringPermissions(int permissions, std::string entryType)
{
    std::string str = std::to_string(permissions);
    while (str.length() < 3)
    {
        str = "0" + str;
    }

    std::string result = "";

    for (int i = 0; i < 3; i++)
    {
        switch (str[i])
        {
        case '0':
            result += "---";
            break;
        case '1':
            result += "--x";
            break;
        case '2':
            result += "-w-";
            break;
        case '3':
            result += "-wx";
            break;
        case '4':
            result += "r--";
            break;
        case '5':
            result += "r-x";
            break;
        case '6':
            result += "rw-";
            break;
        case '7':
            result += "rwx";
            break;
        }
    }

    if (entryType == "folder")
    {
        return "d" + result;
    }
    else
    {
        return "-" + result;
    }
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

        for (auto *folder : current->folders)
        {
            if (folder->name == token)
            {
                current = folder;
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

    for (auto *file : folder->files)
    {
        if (file->name == path)
        {
            return file;
        }
    }

    return nullptr;
}

FileSystem *FileSystem::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new FileSystem();
    }
    return instance;
}