#include "mergeTwoLines.hpp"
#include "transformInputString.hpp"
#include <cstddef>
#include <iostream>
#include <cstring>

int main()
{
    char input[100];
    char line1[50];
    char line2[50];

    int size = 10;
    char* input = new char[size];

    std::cout << "Enter the first line: ";
    std::cin.getline(line1, 50);

    std::cout << "Enter the second line: ";
    std::cin.getline(line2, 50);

    std::strcpy(input, mergeTwoLines(line1, line2));

    std::cout << "Merged line: " << input << '\n';
    delete[] input;
    return 0;
}
