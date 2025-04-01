#include <Arduino.h>

#include <Terminal/Terminal.h>
#include <SD.h>

#define SD_CS 5

Terminal *terminalFrame;

void setup()
{
    if (!SD.begin(SD_CS))
    {
        terminalFrame->Write("SD Card initialization failed!\n");
    }
    else
    {
        terminalFrame->Write("SD Card initialized successfully.\n");
    }

    terminalFrame = new Terminal(250000, 1);
}

void loop()
{
    terminalFrame->Read();
}