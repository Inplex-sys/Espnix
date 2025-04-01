> [!WARNING]
> **This project is in its early stages and may not be fully functional.**

<div>
  <img align="left" width="100" src="https://github.com/Inplex-sys/espnix/assets/69421356/090b8ea2-e131-4995-b0c7-1aba19afd5dc" />
  <h3 align="left">Espnix</h3>
</div>

<hr/>
An Open-Source Unix like system that is made to run on ESP32 and STM32 micro-chips.

## Overview

Espnix provides a lightweight Unix-like environment for microcontrollers, offering familiar shell commands, file system operations, and process management within the constraints of embedded hardware. It brings the power and flexibility of Unix to resource-limited devices.

## Features

-   **Unix-like Shell**: Command-line interface with familiar commands
-   **File System**: SD card-based file system with standard hierarchical structure
-   **Dynamic Execution**: Load and execute binaries directly from SD card
-   **WiFi Management**: Built-in WiFi configuration through `iwctl` command
-   **Module System**: Extensible architecture for adding new functionality
-   **Multi-platform**: Supports both ESP32 and STM32 microcontrollers

## Getting Started

### Prerequisites

-   ESP32 or STM32 development board
-   SD card (minimum 1GB recommended)
-   Arduino IDE or PlatformIO
-   USB cable for programming

### Installation

1. Clone the repository:

    ```
    git clone https://github.com/Inplex-sys/Espnix.git
    ```

2. Open the project in Arduino IDE or PlatformIO

3. Connect your microcontroller via USB

4. Format an SD card as FAT32 and create the initial directory structure:

    ```
    /sys/init
    /bin/
    /lib/
    /etc/
    ```

5. Upload the firmware to your device

### Basic Usage

Once Espnix is running on your device, connect to the serial terminal at 250000 baud. You'll be greeted with the Espnix shell prompt:

```
Espnix booting...
SD Card initialized successfully.
Starting shell...
espnix:/#
```

## Available Native Commands

-   `ls` - List directory contents
-   `cd` - Change current directory
-   `mkdir` - Create new directory
-   `cat` - Display file contents
-   `echo` - Display text or write to files
-   `clear` - Clear terminal screen
-   `iwctl` - Manage wireless connections
-   `run` - Execute binary from SD card

## WiFi Management

Connect to a WiFi network using the iwctl command:

```
espnix:/# iwctl device on
WiFi device turned on
espnix:/# iwctl station scan
Scanning for networks...
espnix:/# iwctl station get-networks
Networks available:
Name                  Security  Signal
Home-Network          psk       ****
espnix:/# iwctl station connect Home-Network mypassword
```

## Creating Binaries

Binaries for Espnix follow a simple format:

```c
#include "espnix.h"

int main(void* context) {
    ExecutionContext* ctx = (ExecutionContext*)context;

    std::string message = "Hello from SD card binary!";
    ctx->loader->ExecuteSysCall(SYS_WRITE, &message);

    return 0;
}
```

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

1. Fork the project
2. Create your feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

-   The Unix and Linux community for inspiration
-   The Arduino and ESP32 community for their excellent libraries
-   All contributors who have helped shape this project
