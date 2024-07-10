#include <string>

#include <Terminal/Terminal.h>

#include "Shell.h"

Shell::Shell() {
    this->prompt = "espnix:~$ ";
}

void Shell::Interpret(std::string command) {
    this->terminal->Write(command);
    this->terminal->Write("\n");
    this->Prompt();
}

void Shell::Prompt() {
    this->terminal->Write(prompt);
}