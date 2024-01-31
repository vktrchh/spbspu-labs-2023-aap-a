#include <iostream>
#include "inputString.hpp"
#include "removing_spaces.hpp"
#include "copyNum.hpp"

int main()
{
  size_t size = 20;
  char* string1 = nullptr;
  char* string2 = nullptr;
  char* inputString1 = nullptr;
  char* inputString2 = nullptr;
  char* inputString3 = nullptr;

  try
  {
    inputString1 = addString(size);
    string1 = deleteSpace(inputString1);
    inputString2 = addString(size);
    inputString3 = addString(size);
    string2 = copyNum(inputString2, inputString3);

  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Memory allocation failed: " << e.what() << "\n";
    return 1;
  }
  catch (...)
  {
    std::cerr << "line error\n";
    if (inputString1 != nullptr)
    {
      delete[] inputString1;
    }
    if (string1 != nullptr)
    {
      delete[] string1;
    }
    if (inputString2 != nullptr)
    {
      delete[] inputString2;
    }
    if (string2 != nullptr)
    {
      delete[] string2;
    }
    if (inputString3 != nullptr)
    {
      delete[] inputString3;
    }
    return 1;
  }

  std::cout << string1 << '\n';
  std::cout << string2 << '\n';

  delete[] inputString1;
  delete[] string1;
  delete[] inputString2;
  delete[] string2;
  delete[] inputString3;
  return 0;
}
