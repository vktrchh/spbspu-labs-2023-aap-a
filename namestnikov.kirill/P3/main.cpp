#include <iostream>
#include <iomanip>
#include <algorithm>
#include "unique_sym_array.hpp"

int main()
{
  using namespace namestnikov;
  char * input1 = new char[20];
  char c1 = 0;
  size_t i1 = 0;
  std::cin >> std::noskipws;
  while ((std::cin >> c1) && (i1 < 19))
  {
    input1[i1++] = c1;
    if (c1 == '\n')
    {
      input1[i1 - 1] = 0;
      break;
    }
  }
  std::cin >> std::skipws;
  std::cin >> std::noskipws;
  char * input2 = new char[20];
  char c2 = 0;
  size_t i2 = 0;
  while ((std::cin >> c2) && (i2 < 19))
  {
    input2[i2++] = c2;
    if (c2 == '\n')
    {
      input2[i2 - 1] = 0;
      break;
    }
  }
  std::cin >> std::skipws;
  char * result = nullptr;
  try
  {
     result = new char[100];
  }
  catch (const std::bad_alloc & e)
  {
    delete[] input1;
    delete[] input2;
    std::cerr << "Error: " << e.what();
    return 1;
  }
  uniqueSymArray(result, input1, input2, i1, i2);
  size_t length = 0;
  for (int i = 0; result[i] != '\0'; ++i)
  {
    ++length;
  }
  std::sort(result, result + length);
  std::cout << result << "\n";
  delete[] input1;
  delete[] input2;
  delete[] result;
}
