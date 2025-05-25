#include <iostream>
#include "file_reader.h"

int main() {
    setlocale(LC_ALL, "RU");
    auto entries = readDataFromFile("main-project/data.txt");
    for (const auto& e : entries) {
        std::cout << e.lastName << " " << e.firstName << " " << e.middleName
            << ": " << e.topic << "\n";
    }
    return 0;
}
