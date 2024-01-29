#include <iostream>
#include <stdexcept>

#include "countNumOfOccurOfLetters.hpp"
#include "sort.hpp"
#include "inputArray.hpp"

int main()
{
  using namespace chistyakov;
  char* array = nullptr;

  try
  {
    array = inputArray(std::cin);
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 2;
  }

  char dictChar[128]{};
  size_t dictNumsOfChar[128]{};
  sortByQuantity(array, dictChar, dictNumsOfChar);

  if (dictChar[1] == 0 || dictChar[2] == 0)
  {
    std::cerr << "There are less than 3 letters in the sequence!\n";
    delete[] array;
    return 1;
  }

  char result[3]{};
  sortCertainNumnerOfItems(dictChar, result, 3);

  for (size_t i = 0; i < 3; ++i)
  {
    std::cout << result[i];
  }
  std::cout << "\n";

  delete[] array;
  return 0;
}
