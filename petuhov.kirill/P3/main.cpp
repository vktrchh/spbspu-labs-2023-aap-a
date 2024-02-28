#include <cstddef>
#include <stdexcept>
#include "streamtostring.hpp"
#include "substractstring.hpp"
#include "removespaces.hpp"

int main()
{
  char *firstString = nullptr;
  char *cloneString = nullptr;
  char *secondString = nullptr;
  size_t length = 0;

  try
  {
    firstString = petuhov::streamToString(std::cin);
    if (firstString == nullptr)
    {
      throw std::runtime_error("Failed to read the first string");
    }

    while (firstString[length] != '\0')
    {
      ++length;
    }

    cloneString = new char[length + 1];
    if (cloneString == nullptr)
    {
      throw std::runtime_error("Failed to allocate memory for cloneString");
    }

    secondString = petuhov::streamToString(std::cin);
    if (secondString == nullptr)
    {
      throw std::runtime_error("Failed to read the second string");
    }

    petuhov::removeSpaces(firstString, cloneString);
    petuhov::substractString(firstString, secondString);
    if (!firstString)
    {
      throw std::runtime_error("First string is empty after subtraction");
    }

    std::cout << firstString << "\n" << cloneString << "\n";
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what();
    delete[] firstString;
    delete[] cloneString;
    delete[] secondString;
    return 1;
  }

  delete[] firstString;
  delete[] cloneString;
  delete[] secondString;
  return 0;
}
