#include "addLat.hpp"
#include "stringManipulations.hpp"

void isaychev::addLat(const char * str1, const char * str2, char * str3)
{
  size_t num = 0;
  fillInUniqueChars(str1, str3, num);
  fillInUniqueChars(str2, str3, num);
  sortCharsAZ(str3);
  str3[num] = '\0';
}
