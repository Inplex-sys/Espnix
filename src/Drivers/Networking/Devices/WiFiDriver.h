#ifndef WIFIDRIVER_H
#define WIFIDRIVER_H

#include <vector>
#include <string>

class WiFiDriver {
private:
    static WiFiDriver* instance;
    WiFiDriver();

public:
    WiFiDriver(const WiFiDriver&) = delete;
    WiFiDriver& operator=(const WiFiDriver&) = delete;

    static WiFiDriver* getInstance();

    bool connect(const char* ssid, const char* password);
    void disconnect();
    std::vector<std::string> listSSIDs();
};

#endif