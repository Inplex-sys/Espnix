#ifndef WiFiDriver_h
#define WiFiDriver_h

#include <Drivers/IDriver.h>

class WiFi;

class WiFiDriver : public IDriver
{
public:
    static WiFiDriver *GetInstance()
    {
        if (instance == nullptr)
        {
            instance = new WiFiDriver();
        }
        return static_cast<WiFiDriver *>(instance);
    }

    void Initialize() override;

    void Shutdown() override;

    void ListNetworks();

    bool Connect(const char *ssid, const char *password);

    void Disconnect();

protected:
    WiFiDriver() = default;

private:
    WiFiDriver(const WiFiDriver &) = delete;
    WiFiDriver &operator=(const WiFiDriver &) = delete;
};

IDriver *IDriver::instance = nullptr;

#endif