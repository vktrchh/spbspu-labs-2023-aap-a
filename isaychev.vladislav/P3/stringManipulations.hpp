#ifndef STRINGMANIPULATIONS_HPP
#define STRINGMANIPULATIONS_HPP

#include <cstdlib>

namespace isaychev
{
  size_t checkForSameElem(const char * str2, char charForCheck);
  void fillInUniqueChars(const char * str_base, char * str_final, size_t & counter);
  void sortCharsAZ(char * str3);
}

#endif
