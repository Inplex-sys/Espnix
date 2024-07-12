#include "MakeDirectoryCommand.h"

#include <FileSystem/Folder.h>
#include <FileSystem/File.h>
#include <FileSystem/FileSystem.h>
#include <Terminal/Terminal.h>
#include <Session/Session.h>

void MakeDirectoryCommand::Execute(const std::vector<std::string> &args, Terminal *terminal)
{
    if (args.size() < 1)
    {
        terminal->Write("mkdir: missing operand\n");
        terminal->Write("Try 'mkdir --help' for more information.\n");
        return;
    }

    if (args[0] == "--help")
    {
        terminal->Write("Usage: mkdir [OPTION]... DIRECTORY...\n");
        terminal->Write("Create the DIRECTORY(ies), if they do not already exist.\n");
        terminal->Write("\n");
        terminal->Write("Mandatory arguments to long options are mandatory for short options too.\n");
        terminal->Write("  -m, --mode=MODE   set file mode (as in chmod), not a=rwx - umask\n");
        terminal->Write("  -p, --parents     no error if existing, make parent directories as needed,\n");
        terminal->Write("                    with their file modes unaffected by any -m option.\n");
        terminal->Write("  -v, --verbose     print a message for each created directory\n");
        terminal->Write("  -Z                   set SELinux security context of each created directory\n");
        terminal->Write("                         to the default type\n");
        terminal->Write("      --context[=CTX]  like -Z, or if CTX is specified then set the SELinux\n");
        terminal->Write("                         or SMACK security context to CTX\n");
        terminal->Write("      --help        display this help and exit\n");
        terminal->Write("      --version     output version information and exit\n");
        terminal->Write("\n");
        terminal->Write("GNU coreutils online help: <https://www.gnu.org/software/coreutils/>\n");
        terminal->Write("Full documentation <https://www.gnu.org/software/coreutils/mkdir>\n");
        terminal->Write("or available locally via: info '(coreutils) mkdir invocation'\n");
        return;
    }

    FileSystem *fs = FileSystem::GetInstance();
    Folder *folder = fs->GetFolder(fs->currentPath);

    for (auto subFolders : folder->folders)
    {
        if (subFolders->name == args[0])
        {
            terminal->Write("mkdir: cannot create directory '" + args[0] + "': File exists\n");
            return;
        }
    }

    Folder *newFolder = new Folder();
    newFolder->name = args[0];
    newFolder->owner = terminal->session->user;

    folder->AddFolder(newFolder);
}