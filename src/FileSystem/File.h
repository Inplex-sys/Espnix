#ifndef FILE_H
#define FILE_H

#include <string>

class File
{
public:
    std::string name;
    std::string *content;
    int owner;
    int permissions;
    int size;
    long creationDate;

    File();
    std::string Read();
    void Write(std::string data);
    void Remove();
};

#endif