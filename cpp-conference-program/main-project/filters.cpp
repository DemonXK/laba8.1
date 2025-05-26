#include "filters.h"

std::vector<ConferenceEntry> filterByAuthor(const std::vector<ConferenceEntry>& list) {
    std::vector<ConferenceEntry> result;
    for (const auto& entry : list) {
        if (entry.lastName == "Иванов" &&
            entry.firstName == "Иван" &&
            entry.middleName == "Иванович") {
            result.push_back(entry);
        }
    }
    return result;
}

int durationMinutes(const ConferenceEntry& e) {
    return (e.endHour * 60 + e.endMinute) - (e.startHour * 60 + e.startMinute);
}

std::vector<ConferenceEntry> filterByDuration(const std::vector<ConferenceEntry>& list) {
    std::vector<ConferenceEntry> result;
    for (const auto& entry : list) {
        if (durationMinutes(entry) > 15) {
            result.push_back(entry);
        }
    }
    return result;
}
