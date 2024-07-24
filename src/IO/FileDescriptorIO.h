#ifndef FILE_DESCRIPTOR_IO_H
#define FILE_DESCRIPTOR_IO_H

#include <unistd.h>
#include <fcntl.h>
#include <string>
#include <stdexcept>

class FileDescriptor
{
public:
    FileDescriptor(int descriptor);

    ssize_t read(void *buffer, size_t count);

    ssize_t write(const void *buffer, size_t count);

    FileDescriptor(const FileDescriptor &) = delete;
    FileDescriptor &operator=(const FileDescriptor &) = delete;

private:
    std::string data;
    int descriptor;
};

#endif