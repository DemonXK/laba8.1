#pragma once
#include "conference_entry.h"
#include <vector>

using CompareFunc = int(*)(const ConferenceEntry*, const ConferenceEntry*);

// ������� ����������
void heapSort(std::vector<ConferenceEntry*>& arr, CompareFunc cmp);
void mergeSort(std::vector<ConferenceEntry*>& arr, CompareFunc cmp);

// ������� ���������
int compareByDurationDesc(const ConferenceEntry* a, const ConferenceEntry* b);
int compareByAuthorTopicAsc(const ConferenceEntry* a, const ConferenceEntry* b);

