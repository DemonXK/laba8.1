#pragma once
#include "conference_entry.h"
#include <vector>

// Фильтрация по автору "Иванов Иван Иванович"
std::vector<ConferenceEntry> filterByAuthor(const std::vector<ConferenceEntry>& list);

// Фильтрация по длительности > 15 минут
std::vector<ConferenceEntry> filterByDuration(const std::vector<ConferenceEntry>& list);

