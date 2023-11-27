#include "seqsym.hpp"
#include "inputArray.hpp"
#include <iostream>
  #include <cctype>
#include <stdexcept>

using namespace spiridonov;

int main()
{
  size_t str = 0;
  size_t * outdatedArray = nullptr;
  size_t * currArray = nullptr;
  size_t* size = nullptr;
  //size_t * array = spiridonov::inputArray(outdatedArray,currArray, str);

  try
  {
    size = spiridonov::inputArray(outdatedArray, currArray, str);
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
  //size_t size = 0;
  //char * array = spiridonov::inputArray(size);

  try
  {
    size_t result = spiridonov::hasConsecutiveDuplicates(currArray, *size);
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
    //delete[] size;
    return 1;
  }
  delete[] currArray;
  std::cout << "Result: " << spiridonov::hasConsecutiveDuplicates(currArray, *size) << "\n";
  return 0;
}
