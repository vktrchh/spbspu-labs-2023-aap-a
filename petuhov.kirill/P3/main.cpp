#include "streamtostring.hpp"
#include "substractstring.hpp"
#include "removespaces.hpp"
#include <cstddef>

int main()
{
  char *firstString = nullptr;
  char * cloneString = nullptr;
  size_t length = 0;

  try
  {
    firstString = petuhov::streamToString(std::cin);
  }
  catch (std::exception &e)
  {
    delete[] firstString;
    std::cerr << e.what();
    return 1;
  }
  while (firstString[length] != '\0')
  {
    ++length;
  }
  try
  {
    cloneString = new char[length + 1];
  }
  catch (std::bad_alloc & e)
  {
    std::cerr << "Not enough memory for clone string";
    return 1;
  }
  cloneString[length + 1] = '\0';

  char *secondString = nullptr;

  try
  {
    secondString = petuhov::streamToString(std::cin);
  }
  catch (std::exception &e)
  {
    delete[] secondString;
    std::cerr << e.what();
    return 1;
  }

  for (size_t i = 0; i <= length; ++i)
  {
    cloneString[i] = firstString[i];
  }

  petuhov::substractString(firstString, secondString);
  petuhov::removeSpaces(cloneString);
  std::cout << firstString << "\n" << cloneString << "\n";
  delete[] firstString;
  delete[] cloneString;
  delete[] secondString;
  return 0;
}
