#include "sort.h"
#include <algorithm>

// ----------- Критерии сравнения ---------------

int compareByDurationDesc(const ConferenceEntry* a, const ConferenceEntry* b) {
    int da = (a->endHour * 60 + a->endMinute) - (a->startHour * 60 + a->startMinute);
    int db = (b->endHour * 60 + b->endMinute) - (b->startHour * 60 + b->startMinute);
    return db - da;
}

int compareByAuthorTopicAsc(const ConferenceEntry* a, const ConferenceEntry* b) {
    if (a->lastName != b->lastName)
        return a->lastName < b->lastName ? -1 : 1;
    return a->topic < b->topic ? -1 : (a->topic > b->topic ? 1 : 0);
}

// ----------- Heap Sort ---------------

void heapify(std::vector<ConferenceEntry*>& arr, int n, int i, CompareFunc cmp) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && cmp(arr[l], arr[largest]) > 0) largest = l;
    if (r < n && cmp(arr[r], arr[largest]) > 0) largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest, cmp);
    }
}

void heapSort(std::vector<ConferenceEntry*>& arr, CompareFunc cmp) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i, cmp);
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0, cmp);
    }
}

// ----------- Merge Sort ---------------

void merge(std::vector<ConferenceEntry*>& arr, int l, int m, int r, CompareFunc cmp) {
    int n1 = m - l + 1, n2 = r - m;
    std::vector<ConferenceEntry*> L(arr.begin() + l, arr.begin() + m + 1);
    std::vector<ConferenceEntry*> R(arr.begin() + m + 1, arr.begin() + r + 1);

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (cmp(L[i], R[j]) <= 0) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSortRecursive(std::vector<ConferenceEntry*>& arr, int l, int r, CompareFunc cmp) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortRecursive(arr, l, m, cmp);
        mergeSortRecursive(arr, m + 1, r, cmp);
        merge(arr, l, m, r, cmp);
    }
}

void mergeSort(std::vector<ConferenceEntry*>& arr, CompareFunc cmp) {
    mergeSortRecursive(arr, 0, arr.size() - 1, cmp);
}
