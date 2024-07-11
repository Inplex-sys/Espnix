#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include <vector>
#include <string>

class Folder;
class File;

class FileSystem {
    private:
        static FileSystem* instance;
        FileSystem();

    public:
        std::string currentPath;
        Folder *root;

        FileSystem(const FileSystem&) = delete;
        FileSystem& operator=(const FileSystem&) = delete;

        static FileSystem* GetInstance();
        Folder *GetFolder(std::string path);
        File *GetFile(std::string path);
};

#endif