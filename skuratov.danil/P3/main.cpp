#include "mergeTwoLines.h"
#include "removeDuplicate.h"
#include "readString.hpp"
#include <cstddef>
#include <iostream>
#include <stdexcept>

int main()
{
    using namespace skuratov;
    size_t size = 20;
    const char* lineOfProgram = "abc";
    try
    {
        char* inputLine = new char[size]{};
        inputLine = readString(inputLine, size);

        if (inputLine[0] == '\0')
        {
            delete[] inputLine;
            throw std::invalid_argument("Empty input");
        }

        char* mergedStrings = new char[size] {};
        char* stringWithRemovedDuplicates = new char[size] {};
        std::cout << mergeTwoLines(mergedStrings, inputLine, lineOfProgram) << '\n';
        std::cout << removeDuplicate(stringWithRemovedDuplicates, lineOfProgram, inputLine, 3, size);
        delete[] inputLine;
        delete[] mergedStrings;
        delete[] stringWithRemovedDuplicates;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}
