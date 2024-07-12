#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include <vector>
#include <string>

class Folder;
class File;

class FileSystemEntry
{
public:
    std::string name;
    int owner;
    int permissions; // Octal representation of permissions
};

class FileSystem
{
private:
    static FileSystem *instance;
    FileSystem();

public:
    std::string currentPath;
    Folder *root;

    FileSystem(const FileSystem &) = delete;
    FileSystem &operator=(const FileSystem &) = delete;

    static FileSystem *GetInstance();
    std::string GetStringPermissions(int permissions, std::string entryType);
    File *GetFile(std::string path);
    Folder *GetFolder(std::string path);
};

#endif