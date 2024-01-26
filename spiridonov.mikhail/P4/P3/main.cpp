#include "consecutiveDup.hpp"
#include "inputArray.hpp"
#include <iostream>

int main()
{
  char* currentArray = nullptr;
  size_t size = 10;

  try
  {
    currentArray = spiridonov::inputArray(std::cin, size);
    if (currentArray != nullptr)
    {
      int result = spiridonov::hasConsecutiveDuplicates(currentArray);
      std::cout << result << "\n";
    }
    else
    {
      std::cerr << "Error in inputArray function" << "\n";
      return 1;
    }
  }
  catch (const std::bad_alloc&)
  {
    std::cerr << "Failed memory allocation" << "\n";
    if (currentArray != nullptr
    {
      delete[] currentArray;
    }
    return 1;
  }
  catch (...)
  {
    std::cerr << "Failed work" << "\n";
    if (currentArray != nullptr)
    {
      delete[] currentArray;
    }
    return 1;
  }

  delete[] currentArray;

  return 0;
}
