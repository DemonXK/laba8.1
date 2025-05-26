#pragma once
#include "conference_entry.h"
#include <vector>

// ���������� �� ������ "������ ���� ��������"
std::vector<ConferenceEntry> filterByAuthor(const std::vector<ConferenceEntry>& list);

// ���������� �� ������������ > 15 �����
std::vector<ConferenceEntry> filterByDuration(const std::vector<ConferenceEntry>& list);

