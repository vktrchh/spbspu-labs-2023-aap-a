#include <cstddef>
#include "streamtostring.hpp"

int main()
{
  char * firstString = nullptr;
  size_t firstStringSize = 0;
  try
  {
    firstString = petuhov::streamToString(std::cin, firstStringSize);
  }
  catch (std::exception & e)
  {
    std::cout << e.what();
    return 1;
  }
  char * secondString = nullptr;
  size_t secondStringSize = 0;
  try
  {
    secondString = petuhov::streamToString(std::cin, secondStringSize);
  }
  catch (std::exception & e)
  {
    std::cout << e.what();
    return 1;
  }
}
