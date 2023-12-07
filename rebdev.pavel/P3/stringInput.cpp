#include "stringInput.hpp"
#include <cstddef>

char * rebdev::inputStr(std::istream & input, char * str)
{
  input >> std::noskipws;

  char sym = 0;
  size_t sizeOfStr = 1;

  while (sym != '\n')
  {
    input >> sym;

    if(!input)
    {
      input >> std::skipws;
      return nullptr;
    }

    str = newStr(str, sizeOfStr);
    str[sizeOfStr - 1] = sym;
    sizeOfStr += 1;
  }

  input >> std::skipws;
  return str;
}

char * rebdev::newStr(char * oldStr, size_t size)
{

  char * newStr = new char[size];
  for(size_t i = 0; i < (size - 1); ++i)
  {
    newStr[i] = oldStr[i];
  }
  delete[] oldStr;
  oldStr = newStr;
  newStr = nullptr;

  return oldStr;
}
