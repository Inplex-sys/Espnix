#include <Arduino.h>
#include <sstream>

#include <FileSystem/Folder.h>
#include <FileSystem/file.h>

#include "FileSystem.h"

FileSystem *FileSystem::instance = nullptr;

FileSystem::FileSystem()
{
    this->root = new Folder();
    this->root->parent = nullptr;

    File *newFile = new File();
    newFile->name = "README.md";
    newFile->Write("Welcome to Espnix a simple Unix-like system for ESP32\n"); 
    newFile->permissions = 0777;

    this->root->AddFile(newFile);

    this->currentPath = "/";
}

FileSystem *FileSystem::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new FileSystem();
    }
    return instance;
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

Folder *FileSystem::GetFolder(std::string path) {
    Folder *current = this->root;
    if (!path.empty() && path[0] != '/') {
        path = "/" + path;
    }

    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(path);

    while (std::getline(tokenStream, token, '/')) {
        if (token == "..") {
            if (current->parent != nullptr) {
                current = current->parent;
            }
        } else if (!token.empty() && token != ".") {
            bool found = false;
            for (auto *folder : current->folders) {
                if (folder->name == token) {
                    current = folder;
                    found = true;
                    break;
                }
            }

            if (!found) {
                return nullptr;
            }
        }
    }

    return current;
}

File *FileSystem::GetFile(std::string path) {
    if (path[0] != '/' && path != ".") {
        path = this->currentPath + "/" + path;
    }

    std::vector<std::string> components;
    std::stringstream ss(path);
    std::string item;
    while (getline(ss, item, '/')) {
        if (!item.empty() && item != ".") {
            if (item == "..") {
                if (!components.empty()) {
                    components.pop_back();
                }
            } else {
                components.push_back(item);
            }
        }
    }

    std::string folderPath;
    for (size_t i = 0; i < components.size() - 1; ++i) {
        folderPath += "/" + components[i];
    }

    Folder *folder = this->GetFolder(folderPath.empty() ? "/" : folderPath);
    if (folder == nullptr) {
        return nullptr;
    }

    std::string fileName = components.back();

    for (auto &file : folder->files) {
        if (file->name == fileName) {
            return file;
        }
    }

    return nullptr;
}

bool FileSystem::FolderExists(std::string path)
{
    Folder *folder = this->GetFolder(path);
    if (folder != nullptr)
    {
        return true;
    }

    return false;
}

