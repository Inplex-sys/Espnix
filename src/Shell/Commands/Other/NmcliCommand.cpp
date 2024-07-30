#include <WiFi.h>

#include <FileSystem/Folder.h>
#include <FileSystem/File.h>
#include <FileSystem/FileSystem.h>
#include <Terminal/Terminal.h>

#include "NmcliCommand.h"

void NmcliCommand::Execute(const std::vector<std::string> &args, Terminal *terminal, FileDescriptor *input, FileDescriptor *output)
{
    if (args.empty())
    {
        terminal->Write("No command provided.\n");
        return;
    }

    const std::string &command = args[0];

    if (command == "device")
    {
        if (args.size() < 2)
        {
            terminal->Write("Usage: device <command> [<args>...]\n");
            return;
        }

        const std::string &subCommand = args[1];

        if (subCommand == "wifi")
        {
            if (args.size() < 3)
            {
                terminal->Write("Usage: device wifi <list|connect> [<SSID> password <password>]\n");
                return;
            }

            const std::string &wifiCommand = args[2];

            if (wifiCommand == "list")
            {
                terminal->Write("Listing available networks...\n");
                terminal->Write("SSID 1\nSSID 2\nSSID 3\n");
            }
            else if (wifiCommand == "connect")
            {
                if (args.size() < 6 || args[3] != "password")
                {
                    terminal->Write("Usage: device wifi connect <SSID> password <password>\n");
                    return;
                }

                const char *ssid = args[4].c_str();
                const char *password = args[5].c_str();

                WiFi.begin(ssid, password);

                while (WiFi.status() != WL_CONNECTED)
                {
                    delay(500);
                    terminal->Write(".");
                }

                terminal->Write("\nConnected to WiFi.\n");
            }
            else
            {
                terminal->Write("Unknown wifi command.\n");
            }
        }
        else
        {
            terminal->Write("Unknown device command.\n");
        }
    }
    else if (command == "disconnect")
    {
        WiFi.disconnect();
        terminal->Write("Disconnected from WiFi.\n");
    }
    else
    {
        terminal->Write("Unknown command.\n");
    }
}