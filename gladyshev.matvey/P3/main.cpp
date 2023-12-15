#include <iomanip>

#include "checkvowel.h"
#include "allocatememory.h"
#include "createarray.h"

int main()
{
  using namespace gladyshev;
  const char vowarr[11] = "AEIOUaeiou";
  char currsym = 0;
  size_t length = 11;
  size_t counter = 0;
  char * baseArray = nullptr;
  baseArray = new char[length];
  std::cin >> std::noskipws;
  while (std::cin >> currsym)
  {
    try
    {
    baseArray[counter] = currsym;
    }
    catch (const std::bad_alloc & e)
    {
      std::cerr << "Error in input\n";
      delete[] baseArray;
      return 1;
    }
    if (currsym == '\n')
    {
      baseArray[counter] = '\0';
      break;
    }
    if ((counter + 1) == length)
    {
      try
      {
        baseArray = newMemory(baseArray, length);
        length += 11;
      }
      catch (const std::bad_alloc & e)
      {
        std::cerr << "Leak\n";
        delete[] baseArray;
        return 1;
      }
    }
    ++counter;
  }
  if (counter == 0)
  {
    std::cerr << "Lack of data\n";
    delete[] baseArray;
    return 1;
  }
  char * finalArray = nullptr;
  try
  {
    finalArray = new char[counter];
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Error in data\n";
    delete[] baseArray;
    return 1;
  }
  finalArray = createFinalArray(baseArray, finalArray, counter, vowarr);
  std::cout << finalArray << "\n";
  delete[] baseArray;
  delete[] finalArray;
  std::cin >> std::skipws;
  return 0;
}
