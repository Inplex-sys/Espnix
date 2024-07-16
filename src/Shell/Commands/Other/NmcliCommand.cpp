#include <Drivers/Networking/Devices/WiFiDriver.h>

#include <Terminal/Terminal.h>

#include "NmcliCommand.h"

void NmcliCommand::Execute(const std::vector<std::string> &args, Terminal *terminal) {
    if (args.empty()) {
        terminal->Write("No arguments provided.\n");
        return;
    }

    auto wifiDriver = WiFiDriver::getInstance();

    if (args[0] == "connect") {
        if (args.size() < 3) {
            terminal->Write("Usage: connect <SSID> <password>\n");
            return;
        }

        terminal->Write("Connecting to WiFi...\n");
        const bool status = wifiDriver->connect(args[1].c_str(), args[2].c_str());
        if (status) {
            terminal->Write("Connected to WiFi.\n");
        } else {
            terminal->Write("Failed to connect to WiFi.\n");
        }
    } else if (args[0] == "disconnect") {
        wifiDriver->disconnect();
        terminal->Write("Disconnected from WiFi.\n");
    } else if (args[0] == "list") {
        const std::vector<std::string> ssids = wifiDriver->listSSIDs();
        for (const auto &ssid : ssids) {
            terminal->Write(ssid + "\n");
        }
    } else {
        terminal->Write("Unknown command.\n");
    }
}