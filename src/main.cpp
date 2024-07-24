#include <Arduino.h>

#include <Terminal/Terminal.h>

Terminal *terminalFrame;

void setup()
{
    terminalFrame = new Terminal(250000, 1);
}

void loop()
{
    terminalFrame->Read();
}