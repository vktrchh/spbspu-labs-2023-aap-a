#include <cstddef>
#include "streamtostring.hpp"
#include "substractString.hpp"

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

  char * substractResult = nullptr;
  try
  {
    substractResult = petuhov::substractString(firstString, firstStringSize, secondString);
    std::cout << substractResult;
    return 0;
  }
  catch (std::exception & e)
  {
    std::cout << e.what();
    return 1;
  }
}
