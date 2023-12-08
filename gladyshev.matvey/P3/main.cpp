#include <iomanip>

#include "allocatememory.h"
#include "checkvowel.h"
#include "createarray.h"

int main()
{
  using namespace gladyshev;
  const size_t vowelSize = 11;
  const char vowels[vowelSize] = "AEIOUaeiou";
  char currsym = '0';
  size_t length = 11;
  size_t counter = 0;
  char * basearray = nullptr;
  char * finalarray = nullptr;
  basearray = new char[length];
  std::cin >> std::noskipws;
  while (std::cin >> currsym)
  {
    if (currsym == '\n')
    {
      break;
    }
    basearray[counter] = currsym;
    if ((counter + 1) == length)
    {
      try
      {
        basearray = newMemory(basearray, length);
        length += 11;
      }
      catch (const std::bad_alloc & e)
      {
        std::cerr << "Leak\n";
        delete[] basearray;
        return 1;
      }
    }
    ++counter;
  }
  try
  {
    finalarray = new char[length];
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Error in data\n";
    delete[] basearray;
    return 2;
  }
  finalarray = createFinalArray(basearray, finalarray, length, vowels, vowelSize);
  std::cout << finalarray << "\n";
  delete[] basearray;
  delete[] finalarray;
  std::cin >> std::skipws;
  return 0;
}
