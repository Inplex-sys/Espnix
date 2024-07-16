#include <WiFi.h>
#include <vector>
#include <string>

#include "WiFiDriver.h"

WiFiDriver* WiFiDriver::instance = nullptr;

WiFiDriver::WiFiDriver() {}

WiFiDriver* WiFiDriver::getInstance() {
    if (instance == nullptr) {
        instance = new WiFiDriver();
    }
    return instance;
}

bool WiFiDriver::connect(const char* ssid, const char* password) {
    unsigned long startAttemptTime = millis();
    unsigned long timeout = 30000;

    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi..");

    while (WiFi.status() != WL_CONNECTED) {
        if (millis() - startAttemptTime > timeout) {
            return false;
        }
        delay(1000);
        Serial.print(".");
    }
    return true;
}

void WiFiDriver::disconnect() {
    WiFi.disconnect();
    Serial.println("Disconnected from WiFi");
}

#include <vector>
#include <string>

std::vector<std::string> WiFiDriver::listSSIDs() {
    std::vector<std::string> ssids;
    Serial.println("Scanning WiFi networks...");
    int n = WiFi.scanNetworks();
    Serial.println("Scan done");
    if (n == 0) {
        Serial.println("No networks found");
    } else {
        for (int i = 0; i < n; ++i) {
            std::string ssid = WiFi.SSID(i).c_str();
            ssids.push_back(ssid);
        }
    }
    return ssids;
}