#include "mergeTwoLines.hpp"
#include <cstddef>

const char* mergeTwoLines(const char* line1, const char* line2)
{
    const char* result = nullptr;
    size_t r = 0;
    size_t i = 0;
    while (r < line1.length() && r < line2.length())
    {
        
        result[i] = line1[r];
        
        result += line2[r];
        ++r;
        ++i;
    }
    while (r < line1.length())
    {
        result += line1[r];
        ++r;
    }
    while (r < line2.length())
    {
        result += line2[r];
        ++r;
    }
    return result;
}
