#include <string>
#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include <vector>

#include <Terminal/Terminal.h>

#include "Shell.h"

class ICommand {
public:
    virtual ~ICommand() = default;
    virtual void Execute(const std::vector<std::string>& args, Terminal* terminal) = 0;
};

class ListCommand : public ICommand {
public:
    void Execute(const std::vector<std::string>& args, Terminal* terminal) override {
        terminal->Write("Executing 'ls' command\n");
    }
};

class ChangeDirectoryCommand : public ICommand {
public:
    void Execute(const std::vector<std::string>& args, Terminal* terminal) override {
        terminal->Write("Executing 'cd' command\n");
    }
};

class Shell {
private:
    std::map<std::string, std::shared_ptr<ICommand>> commandRegistry;
    std::string prompt;

public:
    Terminal *terminal;

    Shell() : terminal(nullptr) {
        commandRegistry["ls"] = std::make_shared<ListCommand>();
        commandRegistry["cd"] = std::make_shared<ChangeDirectoryCommand>();
        this->prompt = "espnix:~$ ";
    }

    void Interpret(const std::string& input) {
        std::istringstream iss(input);
        std::string command;
        std::vector<std::string> args;
        iss >> command;
        std::string arg;
        while (iss >> arg) {
            args.push_back(arg);
        }

        auto it = commandRegistry.find(command);
        if (it != commandRegistry.end()) {
            it->second->Execute(args, terminal);
        } else {
            terminal->Write("Command not found\n");
        }
    }

    void Prompt() {
        terminal->Write(prompt);
    }
};