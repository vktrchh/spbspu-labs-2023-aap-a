#include "mergeTwoLines.hpp"
#include "transformInputString.hpp"
#include "removeDuplicate.hpp"
#include <cstddef>
#include <iostream>
#include <cstring>

int main()
{
    size_t size = 10;
    char* input = new char[size];
    input = transformInputString(input, size);
    if (input == nullptr) 
    {
        delete[] input;
        return 1;
    }
    std::cout << input;

    char* line1 = new char[size];
    char* line2 = new char[size];
    char* line3 = new char[size];
    line3 = mergeTwoLines(line1, line2);
    std::cout << line3;
}
