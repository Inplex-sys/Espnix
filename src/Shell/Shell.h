#ifndef SHELL_HPP
#define SHELL_HPP

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