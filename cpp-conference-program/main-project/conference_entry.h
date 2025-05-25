#pragma once
#include <string>

struct ConferenceEntry {
    int startHour, startMinute;
    int endHour, endMinute;
    std::string lastName;
    std::string firstName;
    std::string middleName;
    std::string topic;
};
