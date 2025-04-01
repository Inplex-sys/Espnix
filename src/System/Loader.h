#ifndef LOADER_H
#define LOADER_H

#include <string>
#include <vector>
#include <map>
#include <SD.h>

class Terminal;

// System call numbers
#define SYS_WRITE 1
#define SYS_READ 2
#define SYS_FILE_OPEN 3
#define SYS_FILE_READ 4
#define SYS_FILE_WRITE 5
#define SYS_FILE_CLOSE 6

// Parameter structures for system calls
struct ReadParams
{
    const char *buffer;
    size_t size;
};

struct FileParams
{
    const char *path;
    int mode; // 0 = read, 1 = write
};

struct FileIOParams
{
    int handle;
    void *buffer;
    size_t size;
};

// Forward declaration for ExecutionContext
class Loader;

// Context passed to binaries when executing
struct ExecutionContext
{
    Terminal *terminal;
    Loader *loader;
};

struct BinaryHeader
{
    uint32_t magic;      // Magic number to identify Espnix binaries (0x45535058 = "ESPX")
    uint32_t version;    // Binary format version
    uint32_t entryPoint; // Entry point offset
    uint32_t dataSize;   // Size of data segment
    uint32_t bssSize;    // Size of BSS segment
    char name[32];       // Name of the binary
};

class Loader
{
private:
    Terminal *terminal;
    std::map<std::string, uint32_t> loadedModules;

    // Execution memory and context
    static const uint32_t MAX_BINARY_SIZE = 262144; // 256KB
    uint8_t *execMemory;
    ExecutionContext *execContext;

    // File handling
    std::map<int, File> openFiles;
    int nextFileHandle = 1;

    struct Process
    {
        std::string name;
        uint32_t memoryOffset;
        bool isRunning;
    };

    std::vector<Process> processes;

    bool verifyHeader(const BinaryHeader &header);
    uint32_t allocateMemory(uint32_t size);

public:
    Loader(Terminal *term);
    ~Loader();

    bool LoadAndExecute(const std::string &path);
    bool LoadModule(const std::string &path);
    void Process();

    int ExecuteSysCall(int callNumber, void *params);
};

#endif