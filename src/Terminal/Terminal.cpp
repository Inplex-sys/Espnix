#include <Arduino.h>
#include <string.h>

#include <Session/Session.h>
#include <Shell/Shell.h>

#include "Terminal.h"

Terminal::Terminal(int baudRate, int user) {
    Serial.begin(baudRate);
    this->baudRate = baudRate;
    this->session = new Session();
    this->session->SetUser(user);

    this->shell = new Shell();
    this->shell->terminal = this;
    this->shell->Prompt();
}

void Terminal::Read() {
    std::string command = Serial.readStringUntil('\n').c_str();
    if (command.length() == 0) {
        return;
    }

    this->shell->Interpret(command);
}

void Terminal::Write(std::string output) {
    Serial.write(output.c_str());
}