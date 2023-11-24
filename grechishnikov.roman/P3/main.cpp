#include <iostream>
#include <cstddef>
#include <exception>
#include "reallocate.hpp"
int main(int argc, char ** argv)
{
  size_t len = 10;
  char * curStr = nullptr;
  try
  {
    curStr = new char[len];
  }
  catch (const std::bad_alloc)
  {
    std::cerr << "Cannot allocate memory\n";
    return 1;
  }

  char chInput = '0';
  size_t curPos = 0;
  std::cin >> std::noskipws;
  while (chInput != '\n')
  {
    std::cin >> chInput;
    curStr[curPos] = chInput;
    curPos++;
    if (curPos % len == 0)
    {
      try
      {
        curStr = reallocate(curStr, len);
      }
      catch (const std::bad_alloc)
      {
        std::cerr << "Cannot reallocate string\n";
        delete[] curStr;
        return 1;
      }
    }
  }
  std::cin >> std::skipws;

  delete[] curStr;
}
