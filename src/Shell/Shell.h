#ifndef SHELL_H
#define SHELL_H

#include <string>

class Terminal;

class Shell {
    private:
        std::string prompt;

    public:
        Terminal* terminal;

        Shell();
        void Interpret(std::string command);
        void Prompt();
};

#endif