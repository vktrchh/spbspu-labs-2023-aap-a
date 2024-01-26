#include <iostream>
#include "consecutiveDup.hpp"
#include "inputArray.hpp"

int main()
{
  char* currentArray = nullptr;
  size_t size = 10;

  try
  {
    currentArray = spiridonov::inputArray(std::cin, size);
    int result = spiridonov::hasConsecutiveDuplicates(currentArray);
    std::cout << result << "\n";
  }
  catch (const std::bad_alloc&)
  {
    std::cerr << "Failed memory allocation" << "\n";
    return 1;
  }
  catch (...)
  {
    std::cerr << "Failed work" << "\n";
    return 1;
  }

  delete[] currentArray;
  std::cin >> std::skipws;

  return 0;
}
