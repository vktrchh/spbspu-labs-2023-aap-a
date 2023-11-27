#include "seqsym.hpp"
#include "inputArray.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
  size_t str = 0;
  size_t * currentArray = nullptr;
  //size_t actualArraySize = 15;
  //size_t* actualArray = new size_t[actualArraySize];
  size_t size = 0;

  try
  {
    currentArray = spiridonov::inputArray(std::cin, size);

    size_t result = spiridonov::hasConsecutiveDuplicates(currentArray, size);
    if (result == 1)
    {
      std::cout << "Array has consecutive duplicates\n";
    }
    else
    {
      std::cout << "Array does not have consecutive duplicates\n";
    }
  }
  catch (const std::exception& e)
  {
    std::cerr << "Failed work: " << e.what() << "\n";
    delete[] currentArray;
    return 2;
  }

  delete[] currentArray;
  return 0;
}
