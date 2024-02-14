#include "streamtostring.hpp"
#include "substractstring.hpp"
#include <cstddef>

int main()
{
  char * firstString = nullptr;
  try
  {
    firstString = petuhov::streamToString(std::cin);
  }
  catch (std::exception & e)
  {
    delete[] firstString;
    std::cout << e.what();
    return 1;
  }
  char * secondString = nullptr;
  try
  {
    secondString = petuhov::streamToString(std::cin);
  }
  catch (std::exception & e)
  {
    delete[] secondString;
    std::cout << e.what();
    return 1;
  }

  petuhov::substractString(firstString, secondString);
  std::cout << firstString;
  return 0;
}
