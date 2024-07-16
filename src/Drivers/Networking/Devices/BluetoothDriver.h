/* #ifndef BLUETOOTHDRIVER_H
#define BLUETOOTHDRIVER_H

class BluetoothDriver {
private:
    static BluetoothDriver* instance;
    BluetoothDriver();

public:
    BluetoothDriver(const BluetoothDriver&) = delete;
    BluetoothDriver& operator=(const BluetoothDriver&) = delete;

    static BluetoothDriver* getInstance();

    void begin(const char* name);
    void connect();
    void disconnect();
};

#endif */