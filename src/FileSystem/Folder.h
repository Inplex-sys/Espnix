#ifndef FOLDER_H
#define FOLDER_H

#include <string>
#include <vector>

class File;
class Folder;

class Folder {
    public:
        std::string foldername;
        std::vector<File> files;
        std::vector<Folder> folders;
        int owner;
        int permissions;

        Folder();
        void AddFile(File* file);
        void AddFolder(Folder* folder);
        void RemoveFile(std::string filename);
        void RemoveFolder(std::string foldername);
};

#endif