#ifndef INPUT_STRING_H
#define INPUT_STRING_H

namespace namestnikov
{
  char * inputString(std::istream & in);
  char * getLongerString(char * string, size_t oldSize, size_t newSize);
}
#endif
