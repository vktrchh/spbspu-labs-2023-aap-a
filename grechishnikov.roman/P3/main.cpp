#include <iostream>
#include <cstddef>
#include <exception>
#include "reallocate.hpp"
#include "countUnic.hpp"

int main()
{
  using namespace grechishnikov;

  size_t len = 10;
  char * curStr = nullptr;
  try
  {
    curStr = new char[len];
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Cannot allocate memory\n";
    return 1;
  }

  char chInput = '0';
  size_t curPos = 0;
  std::cin >> std::noskipws;
  do
  {
    std::cin >> chInput;
    curStr[curPos] = chInput;
    curPos++;
    if (curPos % len == 0 && curStr[curPos] != '\n')
    {
      try
      {
        curStr = reallocate(curStr, len, len + 10);
      }
      catch (const std::bad_alloc &e)
      {
        std::cerr << "Cannot reallocate string\n";
        delete[] curStr;
        return 1;
      }
      len += 10;
    }
  }
  while (chInput != '\n');
  std::cin >> std::skipws;

  std::cout << countUnic(curStr, curPos) << "\n";
  delete[] curStr;
}
