#ifndef TERMINAL_HPP
#define TERMINAL_HPP

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
};

#endif // TERMINAL_HPP