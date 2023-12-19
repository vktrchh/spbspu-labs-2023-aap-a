#include <iostream>
#include <iomanip>

int main()
{
  int num = 10;
  char* input = new char[num];
  size_t i = 0;

  char c = 0;
  std::cin >> std::noskipws;
  while (std::cin >> c)
  {
    if (c == '\n')
    {
      input[i] = '\0';
      break;
    }
    input[i++] = c;

    if (i >= num)
    {
      num *= 2;
      char* symb = new char[num];
      for (int g = 0; g < i; ++g)
      {
        symb[g] = input[g];
      }
      delete[] input;
      input = symb;
    }
  }
  std::cin >> std::skipws;
  std::cout << input << "\n";
  delete[] input;
  return 0;
}
