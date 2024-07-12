#include <string>

#include "File.h"

File::File()
{
    this->permissions = 0777;
    this->content = nullptr;
}

std::string File::Read()
{
    return *this->content;
}

void File::Write(std::string data)
{
    this->size = data.size();

    std::string *chunk = (std::string *)malloc(this->size);
    this->content = chunk;
}

void File::Remove()
{
    free(this->content);
}