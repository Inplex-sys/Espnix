#include <ctime>
#include <iomanip>
#include <sstream>

#include "Utils.h"

std::string Utils::FormatDate(int timestamp)
{
    std::string format = "%b %d %H:%M";

    std::time_t time = static_cast<std::time_t>(timestamp);
    std::tm *localTime = std::localtime(&time);

    std::stringstream ss;
    ss << std::put_time(localTime, format.c_str());
    return ss.str();
}