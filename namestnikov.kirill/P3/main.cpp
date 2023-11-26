#include <iostream>
#include <iomanip>


int main()
{
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
  std::cout << input1 << "\n";
  std::cout << input2 << "\n";
  delete[] input1;
  delete[] input2;
}
