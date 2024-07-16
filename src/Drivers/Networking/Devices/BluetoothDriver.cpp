/* #include <BluetoothSerial.h>

#include "BluetoothDriver.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Make sure to enable it in your SDK configuration.
#endif

BluetoothSerial SerialBT;

BluetoothDriver* BluetoothDriver::instance = nullptr;

BluetoothDriver::BluetoothDriver() {}

BluetoothDriver* BluetoothDriver::getInstance() {
    if (instance == nullptr) {
        instance = new BluetoothDriver();
    }
    return instance;
}
 
void BluetoothDriver::begin(const char* name) {
    SerialBT.begin(name); // Start Bluetooth with given name
    Serial.println("Bluetooth device is ready to pair");
}

void BluetoothDriver::connect() {
    // Placeholder for connect method
    // Implement Bluetooth connection logic here
}

void BluetoothDriver::disconnect() {
    SerialBT.end();
    Serial.println("Bluetooth device is disconnected");
} */