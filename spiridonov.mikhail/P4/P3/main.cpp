#include "seqsym.hpp"
#include "inputArray.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
  size_t str = 0;
  size_t* outdatedArray = nullptr;
  size_t* currArray = new size_t[5];
  size_t *size = 0;

  try
  {
    size = spiridonov::inputArray(outdatedArray, currArray, str);
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 2;
  }

  try
  {
    size_t result = spiridonov::hasConsecutiveDuplicates(currArray,* size);
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
    delete[] currArray;
    return 1;
  }
  delete[] currArray;
  return 0;
}
