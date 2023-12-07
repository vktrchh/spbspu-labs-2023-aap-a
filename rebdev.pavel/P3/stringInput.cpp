#include "stringInput.hpp"
#include <cstddef>

char * rebdev::inputStr(std::istream & input, char * str)
{
  input >> std::noskipws;

  char sym = 0;
  size_t sizeOfStr = 0;

  while (sym != '\n')
  {
    input >> sym;

    if(!input)
    {
      input >> std::skipws;
      return nullptr;
    }

    try
    {
      char * str2 = new char[sizeOfStr + 1];
      for (size_t i = 0; i < sizeOfStr; ++i)
      {
        str2[i] = str[i];
      }

      delete[] str;
      str = str2;
      str2 = nullptr;
    }
    catch (const std::logic_error & e)
    {
      throw e;
    }

    str[sizeOfStr] = sym;
    sizeOfStr += 1;
  }

  input >> std::skipws;
  return str;
}
