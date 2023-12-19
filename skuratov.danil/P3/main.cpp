#include "mergeTwoLines.hpp"
#include <cstddef>
#include <iostream>

int main()
{
    size_t size = 0;
    const char* merged = mergeTwoLines(line1, line2);
    std::cout << input << "\n";
    delete[] input;

    const char* line1 = nullptr;
    const char* line2 = nullptr;
    std::cout << "Enter the first line: ";
    std::getline(std::cin, line1);

    std::cout << "Enter the second line: ";
    std::getline(std::cin, line2);

    const char* merged = mergeTwoLines(line1, line2);
    std::cout << "Merged line: " << merged << '\n';
    return 0;
}
