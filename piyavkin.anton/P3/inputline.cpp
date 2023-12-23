#include <istream>
#include <iostream>
#include "cpline.hpp"
char * inputLine(std::istream & in, size_t & length)
{
  char sym = 0;
  char* old_line = nullptr;
  char* new_line = nullptr;
  while (in >> sym)
  {
    old_line = new_line;
    new_line = new char [length + 1] {};
    piyavkin::cpLine(old_line, new_line, length);
    delete[] old_line;
    new_line[length++] = tolower(sym);
    if (sym == '\n')
    {
      new_line[length-1] = '\0';
      break;
    }
  }
  return new_line;
}
