#ifndef TERMINAL_HP
#define TERMINAL_HP

#include <string>

class Session;
class Shell;

class Terminal {
    public:
        int baudRate;
        Session* session;
        Shell* shell;

        Terminal(int baudRate, int user);
        void Read();
        void Write(std::string output);
        void Clear();
};

#endif // TERMINAL_HPP