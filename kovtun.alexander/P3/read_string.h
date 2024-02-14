#ifndef READ_STRING_H
#define READ_STRING_H

#include <iostream>
#include <iomanip>

namespace kovtun
{
  char * readString(std::istream & in);
  size_t getStringLength(const char * string);
}

#endif
