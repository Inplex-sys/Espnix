#ifndef IDriver_h
#define IDriver_h

class IDriver
{
public:
    virtual void Initialize() = 0;
    virtual void Shutdown() = 0;

    IDriver(const IDriver &) = delete;
    IDriver &operator=(const IDriver &) = delete;

protected:
    IDriver() = default;
    virtual ~IDriver() = default;

    // Singleton instance
    static IDriver *instance;

public:
    static IDriver *GetInstance();
};

IDriver *IDriver::instance = nullptr;

#endif