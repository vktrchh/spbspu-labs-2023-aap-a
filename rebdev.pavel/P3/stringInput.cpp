#include "stringInput.hpp"
#include <cstddef>

char * rebdev::acceptStr(std::istream & input)
{
  char sym = 0;
  size_t sizeOfStr = 0;

  char * str = nullptr;
  char * str2 = nullptr;

  input >> std::noskipws;

  while (sym != '\n')
  {
    input >> sym;
    if(!input)
    {
      delete[] str;
      //input >> std::skipws;
      throw std::logic_error("Bad read!");
    }

    try
    {
      str2 = new char[sizeOfStr + 1];

      for (size_t i = 0; i < sizeOfStr; ++i)
      {
        str2[i] = str[i];
      }
    }
    catch (const std::logic_error & e)
    {
      input >> std::skipws;
      delete[] str;
      delete[] str2;
      throw e;
    }

    delete[] str;
    str = str2;
    str2 = nullptr;
    if (sym != '\n')
    {
      str[sizeOfStr] = sym;
    }
    else
    {
      str[sizeOfStr] = '\0';
    }
    sizeOfStr += 1;
  }

  input >> std::skipws;
  delete[] str2;
  return str;
}
