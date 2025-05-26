#pragma once
#include <vector>
#include "conference_talk.h"

int findLongestTalkDuration(const std::vector<ConferenceTalk>& talks);
std::string formatDuration(int minutes);  // доп. функция форматирования
