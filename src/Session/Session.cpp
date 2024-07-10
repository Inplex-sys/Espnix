#include <ctime>

#include "Session.h"

void Session::SetUser(int user) {
    long timestamp = std::time(0); 

    this->user = user;
    this->creationDate = timestamp;
}