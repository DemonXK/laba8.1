#pragma once
#include <vector>
#include <string>
#include "conference_entry.h"

int findLongestTalkDuration(const std::vector<ConferenceEntry>& entries);
std::string formatDuration(int minutes);
int parseTimeToMinutes(const std::string& timeStr);



