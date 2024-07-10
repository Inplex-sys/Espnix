#ifndef FILE_H
#define FILE_H

#include <string>

class File {
    public:
        std::string filename;
        std::string* content;
        int owner;
        int permissions;
        int size;

        File();
        std::string Read();
        void Write(std::string data);
        void Remove();
        void SetOwner(int user);
        void SetPermissions(int permissions);
};

#endif