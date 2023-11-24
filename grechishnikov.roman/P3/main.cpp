#include <iostream>
#include <cstddef>
#include <exception>

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
  }
  std::cin >> std::skipws;
}
