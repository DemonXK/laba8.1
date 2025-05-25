#include "file_reader.h"
#include "filters.h"
#include "sort.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "RU");
    std::vector<ConferenceEntry> entries = readDataFromFile("data.txt");

    std::cout << "Программа конференции\n";
    std::cout << "1. Все доклады Иванова Ивана Ивановича\n";
    std::cout << "2. Все доклады длительностью > 15 минут\n";
    std::cout << "3. Сортировка докладов\n";
    std::cout << "Выберите действие: ";

    int choice;
    std::cin >> choice;

    if (choice == 1) {
        auto filtered = filterByAuthor(entries);
        for (const auto& e : filtered)
            std::cout << e.lastName << " " << e.topic << "\n";
    }
    else if (choice == 2) {
        auto filtered = filterByDuration(entries);
        for (const auto& e : filtered)
            std::cout << e.lastName << " " << e.topic << "\n";
    }
    else if (choice == 3) {
        std::vector<ConferenceEntry*> ptrs;
        for (auto& e : entries) ptrs.push_back(&e);

        std::cout << "Методы сортировки:\n1. Пирамидальная (Heap Sort)\n2. Слиянием (Merge Sort)\nВаш выбор: ";
        int sortMethod;
        std::cin >> sortMethod;

        std::cout << "Критерии:\n1. По убыванию длительности\n2. По фамилии и теме\nВаш выбор: ";
        int crit;
        std::cin >> crit;

        CompareFunc cmp = (crit == 1) ? compareByDurationDesc : compareByAuthorTopicAsc;

        if (sortMethod == 1)
            heapSort(ptrs, cmp);
        else
            mergeSort(ptrs, cmp);

        std::cout << "\nОтсортированные доклады:\n";
        for (auto p : ptrs) {
            std::cout << p->lastName << " " << p->firstName << " " << p->middleName
                << " | " << p->topic << "\n";
        }
    }
    else {
        std::cout << "Неверный выбор.\n";
    }

    return 0;
}
