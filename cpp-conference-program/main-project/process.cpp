#include "processing.h"
#include <sstream>
#include <iomanip>
#include "conference_talk.h"


int parseTimeToMinutes(const std::string& timeStr) {
    int hours, minutes;
    char colon;
    std::istringstream iss(timeStr);
    iss >> hours >> colon >> minutes;
    return hours * 60 + minutes;
}

int findLongestTalkDuration(const std::vector<ConferenceEntry>& entries) {
    int maxDuration = 0;
    for (const auto& e : entries) {
        int start = e.startHour * 60 + e.startMinute;
        int end = e.endHour * 60 + e.endMinute;
        int duration = end - start;
        if (duration > maxDuration)
            maxDuration = duration;
    }
    return maxDuration;

}

std::string formatDuration(int minutes) {
    int hours = minutes / 60;
    int mins = minutes % 60;
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << hours
        << ":" << std::setw(2) << std::setfill('0') << mins;
    return oss.str();
}
