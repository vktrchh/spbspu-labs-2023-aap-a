#include "seqsym.hpp"
#include "inputArray.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
  size_t str = 0;
  size_t* outdatedArray = nullptr;
  size_t actualArraySize = 15;
  size_t* actualArray = new size_t[actualArraySize];
  size_t size = actualArraySize;

  try
  {
    size_t resultSize = 0;
    actualArray = spiridonov::inputArray(actualArray, &size, resultSize);
    str = resultSize;

    size_t result = spiridonov::hasConsecutiveDuplicates(actualArray, str);
    if (result == 1)
    {
      std::cout << "Array has consecutive duplicates\n";
    }
    else
    {
      std::cout << "Array does not have consecutive duplicates\n";
    }
  }
  catch (const std::runtime_error& e)
  {
    std::cerr << e.what() << "\n";
    delete[] actualArray;
    return 1;
  }
  delete[] actualArray;
  return 0;
}
