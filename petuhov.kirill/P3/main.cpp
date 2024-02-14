#include <cstddef>
#include "streamtostring.hpp"

int main()
{
  char *firstString = nullptr;
  try
  {
    firstString = petuhov::streamToString(std::cin);
    std::cout << firstString;
  }
  catch (...)
  {
  }
}
