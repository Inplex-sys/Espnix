#ifndef NMCLICOMMAND_H
#define NMCLICOMMAND_H

#include <string>
#include <vector>

#include <Shell/Commands/ICommand.h>

class Terminal;

class NmcliCommand : public ICommand
{
public:
    void Execute(const std::vector<std::string> &args, Terminal *terminal) override;
};

#endif