#include "seqsym.hpp"
#include "inputArray.hpp"
#include <iostream>
#include <stdexcept>

using namespace spiridonov;

int main()
{
  char* currentArray = nullptr;
  size_t size = 10;

  try
  {
    currentArray = inputArray(std::cin, size);
    int result = hasConsecutiveDuplicates(currentArray);
    std::cout << result << '\n';
  }
  catch (const std::exception& e)
  {
    std::cerr << "Failed work: " << e.what() << "\n";
    delete[] currentArray;
    return 1;
  }

  delete[] currentArray;

  return 0;
}
