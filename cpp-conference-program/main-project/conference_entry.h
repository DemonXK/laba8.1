#pragma once
#include <string>

struct ConferenceEntry {
    int startHour;
    int startMinute;
    int endHour;
    int endMinute;
    std::string lastName;
    std::string firstName;
    std::string middleName;
    std::string topic;
    std::string startTime;
    std::string endTime;
};
